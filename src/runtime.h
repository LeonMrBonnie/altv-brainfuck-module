#pragma once
#include "brainfuck-module.h"

class BrainfuckRuntime : public alt::IScriptRuntime
{
public:
    BrainfuckRuntime() {};
    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;
    void DestroyImpl(alt::IResource::Impl* impl) override;

    static BrainfuckRuntime& Instance()
	{
		static BrainfuckRuntime _instance;
		return _instance;
	}
};
