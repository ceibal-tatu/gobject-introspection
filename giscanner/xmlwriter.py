# -*- Mode: Python -*-
# GObject-Introspection - a framework for introspecting GObject libraries
# Copyright (C) 2008  Johan Dahlin
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the
# Free Software Foundation, Inc., 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.
#

from __future__ import with_statement

import os

from contextlib import contextmanager
from cStringIO import StringIO
from xml.sax.saxutils import escape, quoteattr

from .libtoolimporter import LibtoolImporter


def _calc_attrs_length(attributes, indent, self_indent):
    if indent == -1:
        return -1
    attr_length = 0
    for attr, value in attributes:
        # FIXME: actually, if we have attributes with None as value this
        # should be considered a bug and raise an error. We are just
        # ignoring them here while we fix GIRParser to create the right
        # ast with the correct attributes.
        if value is None:
            continue
        attr_length += 2 + len(attr) + len(quoteattr(value))
    return attr_length + indent + self_indent


def collect_attributes(tag_name, attributes, self_indent,
                       self_indent_char, indent=-1):
    if not attributes:
        return ''
    if _calc_attrs_length(attributes, indent, self_indent) > 79:
        indent_len = self_indent + len(tag_name) + 1
    else:
        indent_len = 0
    first = True
    attr_value = ''
    for attr, value in attributes:
        # FIXME: actually, if we have attributes with None as value this
        # should be considered a bug and raise an error. We are just
        # ignoring them here while we fix GIRParser to create the right
        # ast with the correct attributes.
        if value is None:
            continue
        if indent_len and not first:
            attr_value += '\n%s' % (self_indent_char * indent_len)
        attr_value += ' %s=%s' % (attr, quoteattr(value))
        if first:
            first = False
    return attr_value


with LibtoolImporter(None, None):
    if 'UNINSTALLED_INTROSPECTION_SRCDIR' in os.environ:
        from _giscanner import collect_attributes
    else:
        from giscanner._giscanner import collect_attributes


class XMLWriter(object):

    def __init__(self):
        self._data = StringIO()
        self._data.write('<?xml version="1.0"?>\n')
        self._tag_stack = []
        self._indent = 0
        self._indent_unit = 2
        self.enable_whitespace()

    # Private

    def _open_tag(self, tag_name, attributes=None):
        if attributes is None:
            attributes = []
        attrs = collect_attributes(
            tag_name, attributes, self._indent,
            self._indent_char,
            len(tag_name) + 2)
        self.write_line(u'<%s%s>' % (tag_name, attrs))

    def _close_tag(self, tag_name):
        self.write_line(u'</%s>' % (tag_name, ))

    # Public API

    def enable_whitespace(self):
        self._indent_char = ' '
        self._newline_char = '\n'

    def disable_whitespace(self):
        self._indent_char = ''
        self._newline_char = ''

    def get_xml(self):
        return self._data.getvalue()

    def write_line(self, line=u'', indent=True, do_escape=False):
        if isinstance(line, str):
            line = line.decode('utf-8')
        assert isinstance(line, unicode)
        if do_escape:
            line = escape(line.encode('utf-8')).decode('utf-8')
        if indent:
            self._data.write('%s%s%s' % (
                    self._indent_char * self._indent,
                    line.encode('utf-8'),
                    self._newline_char))
        else:
            self._data.write('%s%s' % (line.encode('utf-8'), self._newline_char))

    def write_comment(self, text):
        self.write_line('<!-- %s -->' % (text, ))

    def write_tag(self, tag_name, attributes, data=None):
        if attributes is None:
            attributes = []
        prefix = u'<%s' % (tag_name, )
        if data is not None:
            if isinstance(data, str):
                data = data.decode('UTF-8')
            suffix = u'>%s</%s>' % (escape(data), tag_name)
        else:
            suffix = u'/>'
        attrs = collect_attributes(
            tag_name, attributes,
            self._indent,
            self._indent_char,
            len(prefix) + len(suffix))
        self.write_line(prefix + attrs + suffix)

    def push_tag(self, tag_name, attributes=None):
        if attributes is None:
            attributes = []
        self._open_tag(tag_name, attributes)
        self._tag_stack.append(tag_name)
        self._indent += self._indent_unit

    def pop_tag(self):
        self._indent -= self._indent_unit
        tag_name = self._tag_stack.pop()
        self._close_tag(tag_name)
        return tag_name

    @contextmanager
    def tagcontext(self, tag_name, attributes=None):
        self.push_tag(tag_name, attributes)
        try:
            yield
        finally:
            self.pop_tag()


def test():
    w = XMLWriter()
    w.push_tag('repository')
    w.push_tag('namespace')
    w.push_tag('enumeration')
    w.push_tag('member',
               [('name', 'west'),
                ('value', '7'),
                ('c:identifier', 'GTK_ANCHOR_WEST'),
                ('glib:nick', 'west')])

    w.pop_tag()
    w.pop_tag()
    w.pop_tag()
    x = w.get_xml()
    lines = x.split('\n')
    import pprint
    pprint.pprint(lines)
    assert len(lines[3]) < 80, len(lines[3])

if __name__ == '__main__':
    test()
