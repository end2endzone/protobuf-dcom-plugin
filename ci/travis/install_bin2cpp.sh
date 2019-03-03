# Any commands which fail will cause the shell script to exit immediately
set -e

# Validate Travis CI environment
if [ "$TRAVIS_BUILD_DIR" = "" ]; then
  echo "Please define 'TRAVIS_BUILD_DIR' environment variable.";
  exit 1;
fi

export GTEST_ROOT=$TRAVIS_BUILD_DIR/third_parties/googletest/install
export rapidassist_DIR=$TRAVIS_BUILD_DIR/third_parties/RapidAssist/install
export INSTALL_LOCATION=$TRAVIS_BUILD_DIR/third_parties/bin2cpp/install

echo ============================================================================
echo Cloning bin2cpp into $TRAVIS_BUILD_DIR/third_parties/bin2cpp
echo ============================================================================
mkdir -p $TRAVIS_BUILD_DIR/third_parties
cd $TRAVIS_BUILD_DIR/third_parties
git clone "https://github.com/end2endzone/bin2cpp.git"
cd bin2cpp
echo

echo Checking out version v2.2.0...
git checkout 2.2.0
echo

echo ============================================================================
echo Compiling...
echo ============================================================================
mkdir -p build
cd build
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_LOCATION ..
cmake --build .
echo

echo ============================================================================
echo Installing into $INSTALL_LOCATION
echo ============================================================================
make install
echo
