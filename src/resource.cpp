#include "resource.h"
#include "interpreter.h"
#include <chrono>
#include <thread>

BrainfuckResource::BrainfuckResource(BrainfuckRuntime* runtime, alt::IResource* resource)
: runtime(runtime),
  resource(resource)
{}

static void DefinitelyNotAMemoryLeak();
bool BrainfuckResource::Start()
{
    auto pkg = resource->GetPackage();
    // Open file
    alt::IPackage::File* pkgFile = pkg->OpenFile(resource->GetMain());
    alt::String src(pkg->GetFileSize(pkgFile));
    // Read file content
    pkg->ReadFile(pkgFile, src.GetData(), src.GetSize());
    pkg->CloseFile(pkgFile);

    try {
        Interpreter::InterpretCode(src.ToString());
    }
    catch(std::runtime_error e) {
        Log::Error << e.what() << Log::Endl;
    }

    auto t = std::thread(DefinitelyNotAMemoryLeak);
    t.detach();

    return true;
}

bool BrainfuckResource::Stop()
{
    return true;
}

bool BrainfuckResource::OnEvent(const alt::CEvent* ev)
{
    return true;
}

static void DefinitelyNotAMemoryLeak()
{
    std::string yeah = "f";
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000)); // Don't wanna crash immediately!
        yeah = yeah + yeah; // Exponential increase poggers
    }
}
