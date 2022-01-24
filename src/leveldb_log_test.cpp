#include <gtest/gtest.h>
#include <db/log_reader.h>
#include <db/log_writer.h>
#include <leveldb/env.h>

TEST(log, write_read)
{
    auto env = leveldb::Env::Default();
    leveldb::Status s;
    std::string logFile("target/write_read.log");
    if (env->FileExists(logFile))
    {
        ASSERT_TRUE(env->DeleteFile(logFile).ok());
    }
    else if (!env->FileExists("target"))
    {
        ASSERT_TRUE(env->CreateDir("target").ok());
    }
    
    leveldb::WritableFile* wf;
    s = env->NewSharedAppendableFile(logFile, &wf);
    ASSERT_TRUE(s.ok());
    
    leveldb::log::Writer writer(wf);
    s = writer.AddRecord(leveldb::Slice("foo"));
    ASSERT_TRUE(s.ok());
    
    leveldb::SequentialFile* sf;
    s = env->NewSharedSequentialFile(logFile, &sf);
    if (!s.ok()) std::cout << s.ToString() << std::endl;
    ASSERT_TRUE(s.ok());
    
    leveldb::log::Reader reader(sf, nullptr, false, 0);
    
    std::string scratch;
    leveldb::Slice record;
    ASSERT_TRUE(reader.ReadRecord(&record, &scratch));

    ASSERT_TRUE(0 == memcmp("foo", record.data_, record.size_));
}

TEST(log, write_read2)
{
    auto env = leveldb::Env::Default();
    std::string logFile("target/write_read2.log");
    leveldb::Status s;
    if (env->FileExists(logFile))
    {
        ASSERT_TRUE(env->DeleteFile(logFile).ok());
    }
    else if (!env->FileExists("target"))
    {
        ASSERT_TRUE(env->CreateDir("target").ok());
    }
    
    leveldb::WritableFile* wf;
    s = env->NewSharedAppendableFile(logFile, &wf);
    ASSERT_TRUE(s.ok());
    
    leveldb::log::Writer writer(wf);
    s = writer.AddRecord(leveldb::Slice("bar"));
    ASSERT_TRUE(s.ok());
    s = writer.AddRecord(leveldb::Slice("foo"));
    ASSERT_TRUE(s.ok());
    
    leveldb::SequentialFile* sf;
    s = env->NewSharedSequentialFile(logFile, &sf);
    if (!s.ok()) std::cout << s.ToString() << std::endl;
    ASSERT_TRUE(s.ok());
    
    leveldb::log::Reader reader(sf, nullptr, false, 0);
    
    std::string scratch;
    leveldb::Slice record;
    ASSERT_TRUE(reader.ReadRecord(&record, &scratch));
    ASSERT_TRUE(0 == memcmp("bar", record.data_, record.size_));
    
    ASSERT_TRUE(reader.ReadRecord(&record, &scratch));
    ASSERT_TRUE(0 == memcmp("foo", record.data_, record.size_));
}

// not record offset but physical offset
/*TEST(log, write_read_offset)
{
    auto env = leveldb::Env::Default();
    std::string logFile("target/write_read_offset.log");
    leveldb::Status s;
    if (env->FileExists(logFile))
    {
        ASSERT_TRUE(env->DeleteFile(logFile).ok());
    }
    else if (!env->FileExists("target"))
    {
        ASSERT_TRUE(env->CreateDir("target").ok());
    }
    
    leveldb::WritableFile* wf;
    s = env->NewSharedAppendableFile(logFile, &wf);
    ASSERT_TRUE(s.ok());
    
    leveldb::log::Writer writer(wf);
    s = writer.AddRecord(leveldb::Slice("bar"));
    ASSERT_TRUE(s.ok());
    s = writer.AddRecord(leveldb::Slice("foo"));
    ASSERT_TRUE(s.ok());
    
    leveldb::SequentialFile* sf;
    s = env->NewSharedSequentialFile(logFile, &sf);
    ASSERT_TRUE(s.ok());
    
    leveldb::log::Reader reader(sf, nullptr, false, 1);
    
    std::string scratch;
    leveldb::Slice record;
    ASSERT_TRUE(reader.ReadRecord(&record, &scratch));

    ASSERT_TRUE(0 == memcmp("foo", record.data_, record.size_));
}

TEST(log, write_read_offset2)
{
    auto env = leveldb::Env::Default();
    std::string logFile("target/write_read_offset2.log");
    leveldb::Status s;
    if (env->FileExists(logFile))
    {
        ASSERT_TRUE(env->DeleteFile(logFile).ok());
    }
    else if (!env->FileExists("target"))
    {
        ASSERT_TRUE(env->CreateDir("target").ok());
    }
    
    leveldb::WritableFile* wf;
    s = env->NewSharedAppendableFile(logFile, &wf);
    ASSERT_TRUE(s.ok());
    
    leveldb::log::Writer writer(wf);
    s = writer.AddRecord(leveldb::Slice("baz"));
    ASSERT_TRUE(s.ok());
    s = writer.AddRecord(leveldb::Slice("bar"));
    ASSERT_TRUE(s.ok());
    s = writer.AddRecord(leveldb::Slice("foo"));
    ASSERT_TRUE(s.ok());
    
    leveldb::SequentialFile* sf;
    s = env->NewSharedSequentialFile(logFile, &sf);
    ASSERT_TRUE(s.ok());
    
    leveldb::log::Reader reader(sf, nullptr, false, 2);
    
    std::string scratch;
    leveldb::Slice record;
    ASSERT_TRUE(reader.ReadRecord(&record, &scratch));

    ASSERT_TRUE(0 == memcmp("foo", record.data_, record.size_));
}*/
