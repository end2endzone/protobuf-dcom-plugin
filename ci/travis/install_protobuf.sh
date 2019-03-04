# Any commands which fail will cause the shell script to exit immediately
set -e

# Validate Travis CI environment
if [ "$TRAVIS_BUILD_DIR" = "" ]; then
  echo "Please define 'TRAVIS_BUILD_DIR' environment variable.";
  exit 1;
fi

export INSTALL_LOCATION=$TRAVIS_BUILD_DIR/third_parties/bin2cpp/install

echo ============================================================================
echo Cloning protobuf into $TRAVIS_BUILD_DIR/third_parties/protobuf
echo ============================================================================
mkdir -p $TRAVIS_BUILD_DIR/third_parties
cd $TRAVIS_BUILD_DIR/third_parties
git clone "https://github.com/protocolbuffers/protobuf.git"
cd protobuf
echo

echo Checking out version v2.5.0...
git checkout v2.5.0
echo

echo ============================================================================
echo Compiling...
echo ============================================================================
mkdir -p build
cd build
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_LOCATION -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF -DPROTOBUF_ROOT=$TRAVIS_BUILD_DIR/third_parties/protobuf $TRAVIS_BUILD_DIR/src/protobuf
cmake --build .
echo

echo ============================================================================
echo Installing into $INSTALL_LOCATION
echo ============================================================================
make install
echo
