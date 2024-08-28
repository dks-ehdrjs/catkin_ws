#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/adg/catkin_ws/src/GPS_Package/geonav_transform"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/adg/catkin_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/adg/catkin_ws/install/lib/python3/dist-packages:/home/adg/catkin_ws/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/adg/catkin_ws/build" \
    "/usr/bin/python3" \
    "/home/adg/catkin_ws/src/GPS_Package/geonav_transform/setup.py" \
     \
    build --build-base "/home/adg/catkin_ws/build/GPS_Package/geonav_transform" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/adg/catkin_ws/install" --install-scripts="/home/adg/catkin_ws/install/bin"
