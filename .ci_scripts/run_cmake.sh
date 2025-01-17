#!/usr/bin/env bash

case "$BUILD_TARGET" in
"vita")
	docker exec vitasdk /bin/bash -c "mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DVITA_BUILD=ON .."
	;;
"switch")
	docker exec switchdev /bin/bash -c "mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DSWITCH_BUILD=ON .."
	;;
"mac")
	mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" -DSYSTEM_LIBS=OFF ..
	;;
"appimage")
	mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DSYSTEM_LIBS=OFF -DCMAKE_INSTALL_PREFIX=/usr ..
	;;
"linux")
	mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DSYSTEM_LIBS=OFF ..
	;;
"android")
	mkdir build
	;;
*)
	mkdir build && cd build && cmake ..
	;;
esac
