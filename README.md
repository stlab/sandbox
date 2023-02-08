# C++ Devcontainer Sandbox

This project specifies a fully self-contained C++ development environment by combining VSCode Devcontainers, `vcpkg`, and cmake.

**This is alpha-quality software**. Suggestions and issues are [welcome](https://github.com/stlab/sandbox/issues).

# Goals

1. Completely specify a C++ development environment in this repository for rapid experimentation with the latest compiler features and libraries.
2. Make project (files, dependency) management trivially straightforward.
3. Physically co-locate tests with source code for easier development and verification.
4. Offer drop-in benchmarking capabilities
5. Offer "it just works" linting and formatting.

# Building

1. When opening this directory in VSCode, you should be prompted to "reopen folder to develop in a container". Select `Reopen in Container`.
2. Run the command `CMake: Build` either through the [Command Palette](https://code.visualstudio.com/api/ux-guidelines/command-palette) or by hitting F7.
3. From the "Run and Debug" menu (CMD SHIFT D), press the play button for the configuration `(gdb) Launch`. Breakpoints in project files are supported.

Note: CMake configuration will be re-run when a `CMakeLists.txt` is modified and saved.

# Recipes

## Adding a Dependency

1. Update `vcpkg.json` per [vcpkg's Manifest Mode documentation](https://vcpkg.readthedocs.io/en/latest/users/manifests/)
2. In `MyCppApp/CMakeLists.txt`, add a corresponding `find_package` directive, and update `target_link_libraries` to link to your new dependency.
3. Rebuild the project (it should not be necessary to rebuild the environment image).
