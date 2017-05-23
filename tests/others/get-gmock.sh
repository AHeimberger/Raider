# Fusing Google Test Source Files
# https://github.com/google/googletest/blob/master/googletest/docs/AdvancedGuide.md

git clone https://github.com/google/googletest.git googletest

pushd googletest
    echo "gtest version" | tee ../gtest-version.txt
    git describe | tee -a ../gtest-version.txt
    python googlemock/scripts/fuse_gmock_files.py ../gmock/
popd

cp -rf gmock/gmock ../includes/
cp -rf gmock/gtest ../includes/
cp -f gmock/gmock-gtest-all.cc ../sources/

rm -rf googletest
rm -rf gmock
