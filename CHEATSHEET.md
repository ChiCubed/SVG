# SVG cheatsheet

## Compilation

``g++ [your preferred compilation flags] -o main main.cpp SVG.cpp``

## Drawing gradients / using filters

Gradients and filters should be put in the ``<defs>`` at the top of
the SVG file. The helper code will not stop you from putting them elsewhere,
but don't.

Example:

```xml
<defs>
  <linearGradient id="gradient1" x1="0%" y1="0%" x2="100%" y2="100%">
    ...
  </linearGradient>
</defs>
```

One can use gradients/filters for attributes using ``url(#id)``, e.g.:

```xml
<rect ... style="fill: url(#gradient1);filter: url(#blur1);"/>
```

## Styling

Helper functions in the SVG namespace can be used in most cases, e.g. overloads for drawing functions taking Colours as attributes.

List of useful attributes:

- stroke (value: hex (colour) or 'none')
- fill (value: hex (colour) or 'none')
- stroke-opacity (float)
- fill-opacity (float)
- stroke-width (int)
- stroke-linecap (string: one of 'butt', 'square' or 'round'. Designates how to cut off the ends of lines. 'butt' stops the line exactly at the end of the underlying line; 'square' "squares" off the ends so that the line has an extra portion of stroke width on either side; 'round' causes the caps to be rounded.)
- stroke-linejoin (string: one of 'miter', 'round' and 'bevel'. 'miter' causes corners to be completely sharp; 'round' causes corners to be rounded; and 'bevel' behaves like 'miter' but with a lower miterlimit (see below).)
- stroke-miterlimit (float. Controls how far the miter is allowed to extend, i.e. cuts it off after the angle is too sharp.)
- stroke-dasharray (Comma/white-space separated list of lengths and percentages specifying the lengths of alternating dashes and gaps. e.g. 10 5 yields repeating pattern of (stroke of length 10) + (gap of length 5). Odd lengths are repeated until their lengths are even e.g. 5 3 2 is equivalent to 5 3 2 5 3 2.)
- stroke-dashoffset (int, how far into the dash pattern the pattern should be started.)

There are a number of attributes which text possesses:

- text-anchor: 'start', 'middle' or 'end'.
- letter-spacing and kerning
- wordspacing
- font-family
- font-size
- text-decoration: 'underline', 'overline', 'line-through' (and of course 'none')

In addition, many attributes have an additional option "inherit".

stroke-linejoin and stroke-miterlimit only really make sense with regards to ``<polyline>``, where multiple lines are joined.

## IDs

One can set an element's id with the ``id`` attribute, e.g.
``<rect id="abc"></rect>``

## Grouping

To group, inject a ``<g></g>`` into the file.
(Obviously put elements between the opening and closing tags as well.)
Transformations can now be applied to the entire group, e.g.
``<g transform="translate(tx, ty) rotate(rx, ry) scale(sx, sy)>"</g>``
