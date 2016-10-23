# ibm-lmic

This respository was set up to track the code posted by IBM Zurich for
supporting the LoRaWAN MAC on embedded systems. Ths code is written in C,
and supports radios that use the Semtech SX1272 and SX1276 chips. The
repository contains the V1.5 code and V1.6 code.

The repository was imported using Mercurial and then converted to Git
using hggit. Due to bugs in hggit and Mercurial 3.9, I had to use an
unreleased version of hggit, using commit tag [d0ce6ea][1].

The intention is to keep this repository relatively clean, and to fork it
for further experimentation and development. Bugs will be tracked and fixes
will be applied, but major functional changes will happen elsewhere.

[1]: https://bitbucket.org/durin42/hg-git/commits/d0ce6eaebe7b5279d16c1aab7f9bd4aefb471681
