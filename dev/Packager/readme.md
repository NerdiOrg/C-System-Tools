# WAP C++ System Tools Dist Packager

This is a custom tool that I created to automatically create the res object (manifest & icon), compile the starter (start.exe), main program (pkg/run.exe), and move a readme template into the output folder.

Simply enter a version number or name, such as "alpha-0.0.5" or another valid version for the eventual filepath. The output executables from the packager are automatically in /dist/alpha-0.0.5/ folder, allowing easy local version control and releases.

## Packager 2.0 - In progress

For 2.0 I would like to incorporate a source folder that keeps the source as-is for each release. Although Git can be used for version control through branches, I plan to use Packager, starter, and lib/ in other projects, so I am preparing this first software to be its own version control, compiling, and release tool at its core. Functions added to WAP C++ System Tools are intended for reuse elsewhere, so I have a personal library of useful functions.
