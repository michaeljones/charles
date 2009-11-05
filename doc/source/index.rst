.. Charles documentation master file, created by
   sphinx-quickstart on Fri Oct 30 15:22:36 2009.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to Charles' documentation!
==================================

Aim
---

To create a basic ray tracer in C++ with a modular testable code.

Design
------

Classes
~~~~~~~

* World - holds the scene information (objects and lights)

* Object - base class for all objects

  * Sphere - basic scene object

* Light - base class for all lights

  * Point light - the basic light source

* Ray - potentially little more than a glorified vector, holds information about
  the ray we're processing.

* Tracer - Over sees the ray tracing

Dependencies
------------

* Boost for Uniting Testing
* OpenEXR for maths library

Resources
---------

* http://www.codermind.com/articles/Raytracer-in-C++-Introduction-What-is-ray-tracing.html
* http://www.scratchapixel.com/tutorials/index.php?option=com_content&view=article&id=6&catid=1&Itemid=2

