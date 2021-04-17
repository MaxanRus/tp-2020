#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include "Tree.h"

class TreeTestCase : public ::testing::Test {
 protected:
  boost::filesystem::path mTempFileAbs;
  const size_t kCountDirectories = 1000;

 public:
  void CreateTemporaryDirectory();
  std::string GetPathToDirectory();
  FileNode GetFiles();
  FileNode GetDirectories();
  void DeleteTemporaryDirectory();
};

void dfs(const FileNode& v, int d = 0);
void sort(FileNode& v);
