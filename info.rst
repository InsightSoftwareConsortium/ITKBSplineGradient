ITKBSplineGradient
==================

.. image:: https://github.com/InsightSoftwareConsortium/ITKBSplineGradient/workflows/Build,%20test,%20package/badge.svg

Overview
--------

Approximate an image's gradient from a B-spline fit to its intensity.

Installation
------------

To install the Python package::

  pip install itk-bsplinegradient

To build the C++ module, either enable the CMake option in ITK's
build configuration::

  Module_BSplineGradient:BOOL=ON

Or, build the module as a separate project against an ITK build tree::

  git clone https://github.com/InsightSoftwareConsortium/ITKBSplineGradient
  mkdir ITKBSplineGradient-build
  cd ITKBSplineGradient-build
  cmake -DITK_DIR=/path/to/ITK-build ../ITKBSplineGradient
  cmake --build .

License
-------

This software is distributed under the Apache 2.0 license. Please see the
*LICENSE* file for details.
