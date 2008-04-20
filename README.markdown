# rverse

A set of libraries and utilities to facilitate reverse engineering

### TODOs

* TEST TEST TEST (with rspec, ideally)
* Decode the additional information in the dysymtab load command, to support other kinds of relocations and dynamic linker behavior
* Let the ObjC type descriptor parser understand ObjC++
* Have the ObjC module detect ObjC1/1.5/2 and search for structures accordingly
* Output ObjC information to a metaformat (for eventual computer reasoning) which could then be output to ObjC syntax if desired
* Test C / ObjC grammars and implement header/prototype parsing for them, to avoid redundant information being added to header output (and eventually, to build a database of parameter and return types to aid in simple decompilation of function calls and associated variables)
* Add a C++ grammar and integrate it into ObjC if necessary
* Consider adding support for gcc extensions to C/ObjC/C++ as most of the headers we'll be dealing with come from gcc/g++
* Abstract away the Image class and have MachO simply return subclasses of it
* Fix the Image virtual memory IO object to prevent reading past the edge of segment boundaries
* Reorder directories to make more sense

### Dependencies

* Treetop

### How to use

For now, just run rverse.rb with the Objective C 2.0 binary you'd like to dump as its parameter. It will output the header contents to stdout (if you're lucky).