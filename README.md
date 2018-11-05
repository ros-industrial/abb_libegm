# abb_libegm

[![Travis CI Status](https://travis-ci.org/ros-industrial/abb_libegm.svg?branch=master)](https://travis-ci.org/ros-industrial/abb_libegm)

[![support level: vendor](https://img.shields.io/badge/support%20level-vendor-brightgreen.png)](http://rosindustrial.org/news/2016/10/7/better-supporting-a-growing-ros-industrial-software-platform)

## Important Note

RobotWare `6.07` introduced major changes in the EGM communication protocol, and this library has not been updated to support those changes yet.

**Avoid using this library with RobotWare 6.07 at the moment.**

## Overview

A C++ library for interfacing with ABB robot controllers supporting *Externally Guided Motion* (EGM). See the *Application manual - Controller software IRC5* for a detailed description of what EGM is and how to use it.

See [abb_librws](https://github.com/ros-industrial/abb_librws) for a companion library that interfaces with *Robot Web Services* (RWS).

### Sketch

The following is a conceptual sketch of how this EGM library can be viewed, in relation to an ABB robot controller as well as the RWS companion library mentioned above.

![EGM sketch](docs/images/egm_sketch.svg)

### Requirements

* RobotWare versions between `6.0` and `6.06.01` (higher versions are to be considered incompatible at the moment).
* A license for the RobotWare option *Externally Guided Motion* (`689-1`).

### Dependencies

* [Boost C++ Libraries](https://www.boost.org)
* [Google Protocol Buffers](https://developers.google.com/protocol-buffers)

### Limitations

This library is intended to be used with the UDP variant of EGM, and it supports the following EGM modes:

* Joint Mode
* Pose Mode

### Recommendations

* This library has been verified to work with RobotWare `6.06.01`. Other version are expected to work, but this cannot be guaranteed at the moment.
* It is a good idea to perform RobotStudio simulations before working with a real robot.
* It is prudent to familiarize oneself with general safety regulations (e.g. described in ABB manuals).
* Consider cyber security aspects, before connecting robot controllers to networks.

## Acknowledgements

The **core development** has been supported by the European Union's Horizon 2020 project [SYMBIO-TIC](http://www.symbio-tic.eu/).
The SYMBIO-TIC project has received funding from the European Union's Horizon 2020 research and innovation programme under grant agreement no. 637107.

<img src="docs/images/symbio_tic_logo.png" width="250">

The **open-source process** has been supported by the European Union's Horizon 2020 project [ROSIN](http://rosin-project.eu/).
The ROSIN project has received funding from the European Union's Horizon 2020 research and innovation programme under grant agreement no. 732287.

<img src="docs/images/rosin_logo.png" width="250">

The opinions expressed reflects only the author's view and reflects in no way the European Commission's opinions.
The European Commission is not responsible for any use that may be made of the contained information.

### Special thanks

Special thanks to [gavanderhoorn](https://github.com/gavanderhoorn) for guidance with open-source practices and ROS-Industrial conventions.
