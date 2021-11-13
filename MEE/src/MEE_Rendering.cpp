#include "MEE_Rendering.h"
#include "MEE_Graphics.h" // Deberia cambiar el nombre a graphics module o graphics module interface
#include "MEE_Texture.h"
#include "MEE_Maths.h"
#include "MEE_Camera.h"
#include "MEE_Logging.h"

//TODO HACER VERIFICAIONES EN TODAS LAS LLAMADAS PARA VER QUE SEAN VÁLIDAS

#define MEE_CHECK_FUNCTION(FUNC_NAME,FUNCTION)\
try\
{\
    FUNCTION;\
}\
catch(...)\
{\
	std::string message ="An error ocurred while calling ";\
	message += #FUNC_NAME;\
	message += " in MEE_GRAHICS";\
    MEE_LOGGER::Error(message.c_str());\
}

bool MEE::RenderingManager::Init()
{
     //This function checks if all essential input bindings are correctrly set
    bool success = true;

    bool essentials_set =
        MEE_SetRenderColor && MEE_RenderTexture2D && MEE_CreateTexture2D &&
        MEE_RenderClear; // Add more to essentials

    success = essentials_set;

    return success;
}

void MEE::RenderingManager::RenderClear()
{
    MEE_CHECK_FUNCTION(MEE_RenderClear, MEE_RenderClear());
}

void MEE::RenderingManager::SetRenderColor(int r, int g, int b, int a)
{
    MEE_CHECK_FUNCTION(MEE_SetRenderColor,MEE_SetRenderColor(r, g, b, a));
}

void MEE::RenderingManager::SetRenderViewport(int x, int y, int w, int h)
{
    MEE_CHECK_FUNCTION(MEE_SetRenderViewport, MEE_SetRenderViewport(x, y, w, h));
}

void MEE::RenderingManager::InitGL()
{
    MEE_CHECK_FUNCTION(MEE_InitGL, MEE_InitGL());
}

void MEE::RenderingManager::RenderLine(float x1, float y1, float x2, float y2, RenderingType type)
{
    MEE_CHECK_FUNCTION(MEE_RenderLine, MEE_RenderLine(x1, y1, x2, y2));
}

void MEE::RenderingManager::RenderPoint(float x, float y, RenderingType type)
{
    MEE_CHECK_FUNCTION(MEE_RenderPoint, MEE_RenderPoint(x, y));
}

void MEE::RenderingManager::RenderPolygon(const std::vector<Vector2>& vertices, RenderingType type)
{
    Vector2 cameraPos = currentCamera.lock()->GetPosition();
    if (type == RenderingType::NonPhysical)
    {
        cameraPos = Vector2::Zero();
    }

    std::vector<float> points; // deberia cambiarlo a array
    float ppu = PIXELS_PER_UNIT;
    int v = 0;

    for (int i = 0; i < vertices.size() * 2; i += 2)
    {
        points.push_back((vertices[v].x - cameraPos.x) * ppu);
        points.push_back((vertices[v].y - cameraPos.y) * ppu);
        v++;
    }
    MEE_CHECK_FUNCTION(MEE_RenderPolygon, MEE_RenderPolygon(points));

}

void MEE::RenderingManager::RenderSolidPolygon(const std::vector<Vector2>& vertices, RenderingType type)
{
    Vector2 cameraPos = currentCamera.lock()->GetPosition();
    if (type == RenderingType::NonPhysical)
    {
        cameraPos = Vector2::Zero();
    }

    std::vector<float> points; // deberia cambiarlo a array
    float ppu = PIXELS_PER_UNIT;
    int v = 0;

    for (int i = 0; i < vertices.size() * 2; i += 2)
    {
        points.push_back((vertices[v].x - cameraPos.x) * ppu);
        points.push_back((vertices[v].y - cameraPos.y) * ppu);
        v++;
    }
    MEE_CHECK_FUNCTION(MEE_RenderSolidPolygon, MEE_RenderSolidPolygon(points));
}

void MEE::RenderingManager::RenderCircle(float x, float y, float radius, RenderingType type)
{
    MEE_CHECK_FUNCTION(MEE_RenderCircle, MEE_RenderCircle(x, y, radius));
}

void MEE::RenderingManager::RenderSolidCircle(float x, float y, float radius, RenderingType type)
{
    MEE_CHECK_FUNCTION(MEE_RenderSolidCircle, MEE_RenderSolidCircle(x, y, radius));
}

void MEE::RenderingManager::RenderTexture2D(std::weak_ptr<Texture2D> texture, float x, float y, float scale_x, float scale_y, float angle, int clipX, int clipY, int clipW, 
    int clipH, bool h_flip, bool v_flip, RenderingType type)
{

    Texture2D* tex = texture.lock().get();
    MEE_Texture2D moduleTexture = static_cast<MEE_Texture2D>(tex);

    Vector2 cameraPos = currentCamera.lock()->GetPosition();

    if (type == RenderingType::Physical)
    {
        x = x - (cameraPos.x * PIXELS_PER_UNIT);
        y = y - (cameraPos.y * PIXELS_PER_UNIT);
    }

    MEE_CHECK_FUNCTION(MEE_RenderTexture2D,
        MEE_RenderTexture2D
        (moduleTexture, x, y, scale_x, scale_y, angle,
         clipX, clipY, clipW, clipH, h_flip, v_flip));
}

MEE::Texture2D* MEE::RenderingManager::CreateTexture2D(const std::string& path)
{
    MEE_Texture2D pointer = nullptr;
    MEE_CHECK_FUNCTION(MEE_CreateTexture2D, pointer = MEE_CreateTexture2D(path.c_str()));
    return (Texture2D*) pointer;
}

void MEE::RenderingManager::RenderDebugGrid(RenderingType type)
{
    MEE_CHECK_FUNCTION(MEE_RenderDebugGrid, MEE_RenderDebugGrid());
}

void MEE::RenderingManager::SetPixelsPerUnit(float ppu)
{
    PIXELS_PER_UNIT = ppu;
    UNITS_PER_PIXEL = 1.0F / ppu;
}

float MEE::RenderingManager::GetPixelsPerUnit()
{
    return PIXELS_PER_UNIT;
}

float MEE::RenderingManager::GetUnitsPerPixel()
{
    return UNITS_PER_PIXEL;
}

void MEE::RenderingManager::RenderTransform(const Vector2& position)
{
    Vector2 cameraPos = currentCamera.lock()->GetPosition();

    MEE_CHECK_FUNCTION(MEE_SetRenderColor, MEE_SetRenderColor(0, 255, 0, 255));
    const float radius = 1.0F;
    MEE_CHECK_FUNCTION(MEE_RenderCircle, MEE_RenderCircle((position.x - cameraPos.x) * PIXELS_PER_UNIT, (position.y - cameraPos.y) * PIXELS_PER_UNIT, radius);)
    MEE_CHECK_FUNCTION(MEE_SetRenderColor, MEE_SetRenderColor(53, 40, 230, 255));
}

void MEE::RenderingManager::SetCurrentCamera(std::weak_ptr<Camera> camera)
{
    currentCamera = camera;
}
