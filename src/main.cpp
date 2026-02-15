#include <iostream>

#include "core/FileLoader.h"
#include "html/Tokenizer.h"
#include "html/Parser.h"
#include "render/Renderer.h"
#include "render/SDLWindow.h"
#include "render/SDLRenderer.h"

using namespace std;
int main()
{
    string html = FileLoader::readFile("test_pages/index.html");

    if (html.empty())
        return 1;

    Tokenizer tokenizer;
    auto tokens = tokenizer.tokenize(html);

    Parser parser;
    DOMNode *dom = parser.parse(tokens);

    SDLWindow window(900, 600);
    SDLRenderer renderer(window.getRenderer());

    while(window.isRunning())
    {
        window.pollEvents();
        renderer.render(dom);
        SDL_Delay(16); //~60 FPS
    }

    delete dom;

    return 0;
}
