# test sources for [gn-deps](https://github.com/dyu/gn-deps/)

### Fetch deps
```sh
git clone --depth 1 --single-branch -b ns https://github.com/dyu/gn-build
git clone --depth 1 --single-branch -b master https://github.com/dyu/gn-deps

# if windows, execute this via msys2 bash
./gn-deps/fetch.sh
```

### Configure gn
Linux   
```sh
gn gen gn-out --args='gcc_cc="gcc" gcc_cxx="g++" symbol_level=0 is_debug=false is_clang=false is_official_build=true'
```
Windows
```sh
gn gen gn-out --args="visual_studio_path=\"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\" visual_studio_version=\"2015\" symbol_level=0 is_debug=false is_clang=false is_official_build=true"
   ```

### Build
```sh
ninja -C gn-out
```

