#include <cassert>

#include "leveldb/db.h"

int main() {
  // 1. Open
  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, "testdb", &db);
  assert(status.ok());

  // 2. Put
  leveldb::WriteOptions write_options;
  status = db->Put(write_options, "hello", "world");
  assert(status.ok());

  // 3. Get
  std::string value;
  status = db->Get(leveldb::ReadOptions(), "hello", &value);
  assert(status.ok());
  assert(value == "world");

  // 4. Close
  delete db;

  return 0;
}