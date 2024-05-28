/* angelscript.h - Angelscript integration header
 *
 * NVGT - NonVisual Gaming Toolkit
 * Copyright (c) 2022-2024 Sam Tupy
 * https://nvgt.gg
 * This software is provided "as-is", without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
 * Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
 * 1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
*/

#pragma once

#include <string>
#include <angelscript.h>
#include "contextmgr.h"

extern std::string g_compiled_basename;
extern std::string g_CommandLine;
extern std::vector<asIScriptContext*> g_ctxPool;
extern std::vector<std::string> g_IncludeDirs;
extern std::vector<std::string> g_IncludeScripts;
extern CContextMgr* g_ctxMgr;

void ShowAngelscriptMessages();
int ConfigureEngine(asIScriptEngine* engine);
int ExecuteScript(asIScriptEngine* engine, const std::string& scriptFile);
#ifndef NVGT_STUB
	int               CompileScript(asIScriptEngine* engine, const std::string& scriptFile);
	int SaveCompiledScript(asIScriptEngine* engine, unsigned char** output);
int CompileExecutable(asIScriptEngine* engine, const std::string& scriptFile);
void              InitializeDebugger(asIScriptEngine *engine);
#else
int LoadCompiledScript(asIScriptEngine* engine, unsigned char* code, asUINT size);
int LoadCompiledExecutable(asIScriptEngine* engine);
#endif
void MessageCallback(const asSMessageInfo* msg, void* param);
asIScriptContext* RequestContextCallback(asIScriptEngine* engine, void* param);
void ReturnContextCallback(asIScriptEngine* engine, asIScriptContext* ctx, void* param);
void ExceptionHandlerCallback(asIScriptContext* ctx, void* obj);
asUINT GetTimeCallback();
void RegisterUnsorted(asIScriptEngine* engine);
