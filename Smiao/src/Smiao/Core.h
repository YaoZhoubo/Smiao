#pragma once

#ifdef SM_ENGINE
#define SM_API __declspec(dllexport)
#else
#define SM_API __declspec(dllimport)
#endif // SM_ENGINE
