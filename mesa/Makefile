MESON_SETUP_KEYS = -Dvulkan-drivers=swrast -Dgallium-drivers=llvmpipe -Dplatforms=x11 -Dvideo-codecs=""
MESON_BUILD_DIR = build
MESON_BUILD_KEYS = --reconfigure --buildtype release --libdir lib --prefix $(HOME)/mesa


C_KEYS = "-pthread -lpthread -latomic -lstdc++ -lm -I/usr/share/verilator/include -I/usr/share/verilator/include/vltstd /usr/share/verilator/include/verilated_dpi.cpp"

NINJA_KEYS = -C build install

VKCUBE = ./../vkcube/build/vkcube

all: meson_setup ninja_build run

meson_setup:
	meson setup $(MESON_SETUP_KEYS) $(MESON_BUILD_DIR) $(MESON_BUILD_KEYS)

ninja_build:
	ninja $(NINJA_KEYS)

build: meson_setup ninja_build

run:
	$(VKCUBE)
