mkdir -p build
mkdir -p build/graph
mkdir -p build/config
mkdir -p build/fonts
mkdir -p build/resource/
mkdir -p build/data
mkdir -p build/data/prolog 
mkdir -p build/data/prolog/addressable 
mkdir -p build/data/prolog/unaddressable
cp -n prolog/base_rules.pl build/config/
cp -n fonts/* build/fonts/
cp -n resource/* build/resource/
cp -n simpleView.config build/config/
cp -n dimControl.config build/config/
cp -n excludePackage.config build/config/
cp -n excludeClass.config build/config/
cd external/imgui/
git checkout origin/features/shadows
cd ../..
cd external/threepp/
git checkout 32210bc3b32ee00475d707ae536f09869ab09cd7
cd ../..
cd external/re2/
git checkout b7e96b34c0945fccb8b5282404f82c7ab0843717
cd ../..
cmake -DGLFW_INSTALL=OFF -DGLFW_BUILD_WAYLAND=OFF -DANTLR_BUILD_CPP_TESTS=OFF -DBUILD_TESTING=OFF -DINSTALL_DOCUMENTATION=OFF -DTHREEPP_BUILD_EXAMPLES=OFF -DTHREEPP_BUILD_TESTS=OFF -DTHREEPP_EMBEDDED_GLFW_WITH_X11=ON -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=$1/scripts/buildsystems/vcpkg.cmake -S . -B build
