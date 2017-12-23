Low Level Virtual Machine (LLVM)
================================

I put personally modified LLVM here.  I add following copied target to show
an easy first step to create a new backend.  You can create your own new
backend using an existing backend similar to your target.  Copy it and
modify it using similar techniques I applied on this Simple target. :)

 - Simple: Copied and renamed Sparc target with very little modificatins.
   (36 files changed, 161 insertions, 144 deletions)

Low Level Virtual Machine (LLVM)
================================

This directory and its subdirectories contain source code for LLVM,
a toolkit for the construction of highly optimized compilers,
optimizers, and runtime environments.

LLVM is open source software. You may freely distribute it under the terms of
the license agreement found in LICENSE.txt.

Please see the documentation provided in docs/ for further
assistance with LLVM, and in particular docs/GettingStarted.rst for getting
started with LLVM and docs/README.txt for an overview of LLVM's
documentation setup.

If you are writing a package for LLVM, see docs/Packaging.rst for our
suggestions.


