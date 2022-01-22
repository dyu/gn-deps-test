# test sources for [gn-deps](https://github.com/dyu/gn-deps/)

### Fetch deps
```sh
git clone --depth 1 --single-branch -b build https://github.com/dyu/gn-build.git build
git clone --depth 1 --single-branch -b build https://github.com/dyu/gn-deps.git

# if windows, execute this via msys2 bash
./gn-deps/fetch.sh all
```

### Configure gn
Linux
```sh
gn gen gn-out --args='gcc_cc="gcc-9" gcc_cxx="g++-9" symbol_level=0 is_debug=false is_clang=false is_official_build=true'
```
Mac
```sh
gn gen gn-out --args='symbol_level=0 is_debug=false is_clang=true is_official_build=true'
```
Windows
```sh
gn gen gn-out --args="visual_studio_path=\"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\" visual_studio_version=\"2015\" symbol_level=0 is_debug=false is_clang=false is_official_build=true"
   ```

### Build
```sh
ninja -C gn-out
```

### Run tests
```sh
./run-tests.sh
```

