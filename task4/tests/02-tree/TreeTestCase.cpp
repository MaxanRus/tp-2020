#include "TreeTestCase.h"
#include "Tree.h"

void TreeTestCase::CreateTemporaryDirectory() {
  mTempFileAbs = boost::filesystem::unique_path("/tmp/TreeTestCase/");
  if (!boost::filesystem::exists(mTempFileAbs))
    boost::filesystem::create_directory(mTempFileAbs);
  for (int i = 0; i < kCountDirectories; ++i) {
    while (!boost::filesystem::exists(boost::filesystem::unique_path("/tmp/TreeTestCase/" + std::to_string(i)))) {
      boost::filesystem::create_directory(boost::filesystem::unique_path("/tmp/TreeTestCase/" + std::to_string(i)));
    }
    while (!boost::filesystem::exists("/tmp/TreeTestCase/file_" + std::to_string(i))) {
      std::ofstream tmp("/tmp/TreeTestCase/file_" + std::to_string(i));
      tmp.close();
    }
  }
}
std::string TreeTestCase::GetPathToDirectory() {
  return mTempFileAbs.string();
}
FileNode TreeTestCase::GetFiles() {
  FileNode f;
  f.name = ".";
  f.is_dir = true;
  for (int i = 0; i < kCountDirectories; ++i) {
    f.children.push_back(FileNode{std::to_string(i), true, {}});
    f.children.push_back(FileNode{"file_" + std::to_string(i), false, {}});
  }
  return f;
}
FileNode TreeTestCase::GetDirectories() {
  FileNode f;
  f.name = ".";
  f.is_dir = true;
  for (int i = 0; i < kCountDirectories; ++i) {
    f.children.push_back(FileNode{std::to_string(i), true, {}});
  }
  return f;
}
void TreeTestCase::DeleteTemporaryDirectory() {
  while (boost::filesystem::exists(mTempFileAbs)) {
    try {
      boost::filesystem::remove_all(mTempFileAbs);
    } catch (...) {}
  }
}
void sort(FileNode& v) {
  std::sort(v.children.begin(), v.children.end(), [](const auto& a, const auto& b) {
    if (a.is_dir != b.is_dir)
      return a.is_dir < b.is_dir;
    return a.name < b.name;
  });
  for (auto& i: v.children)
    sort(i);
}

TEST_F(TreeTestCase, TestGetTree) {
  CreateTemporaryDirectory();

  auto tree = GetTree(GetPathToDirectory(), false);
  auto true_tree = GetFiles();
  sort(tree);
  sort(true_tree);
  ASSERT_TRUE(tree == true_tree);

  tree = GetTree(GetPathToDirectory(), true);
  true_tree = GetDirectories();

  sort(tree);
  sort(true_tree);
  ASSERT_TRUE(tree == true_tree);

  DeleteTemporaryDirectory();
}

TEST_F(TreeTestCase, TestThrow) {
  CreateTemporaryDirectory();

  EXPECT_THROW(GetTree("/tmp/TreeTestCase/non-existent_directory", false), std::invalid_argument);
  EXPECT_THROW(GetTree("/tmp/TreeTestCase/file_19", true), std::invalid_argument);

  DeleteTemporaryDirectory();
}

TEST_F(TreeTestCase, TestFilterEmptyNodes) {
  CreateTemporaryDirectory();

  FileNode first_test{"/tmp/TreeTestCase/non-existent_directory", false, {}};
  FilterEmptyNodes(first_test, "/tmp/TreeTestCase/");

  first_test.name = "/tmp/TreeTestCase/";
  FilterEmptyNodes(first_test, "tmp/TreeTestCase/");

  auto tree = GetTree(GetPathToDirectory(), false);
  sort(tree);
  FilterEmptyNodes(tree, "tmp/TreeTestCase/");

  DeleteTemporaryDirectory();
}