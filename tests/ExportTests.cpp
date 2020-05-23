#include "ExportTests.h"
#include "../src/structures/Program.h"

// export a="aaaa"
Program generateSimpleExport() {

    Value* name = new Value("a");
    Value* newValue = new Value("aaaa");
    Variable* v = new Variable(*name, *newValue, true);

    std::vector<VarPip *> varpips = {v};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}

void testParserGenerateSimpleExport() {
    Program *p = parse("export a=\"aaaa\"");
    Program t = generateSimpleExport();
    assert(p->isEqual(&t));
}