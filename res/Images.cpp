#include "../util/util.h"

#include "glad/glad.h"
#include "stb_image.h"
#include "../file/FileManager.h"
#include "../error/ErrorManager.h"
#include "Images.h"


// Simple helper function to load an image into a OpenGL texture with common settings
bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height) {
    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL) {
        return false;
    }

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    return true;
}

unsigned int Images::classScopeIconId = 0;
unsigned int Images::fieldIconId = 0;
unsigned int Images::methodIconId = 0;
unsigned int Images::parameterIconId = 0;
unsigned int Images::varIconId = 0;
unsigned int Images::returnIconId = 0;
unsigned int Images::lineIconId = 0;
unsigned int Images::orderLineIconId = 0;
unsigned int Images::segmentLineIconId = 0;
unsigned int Images::anyIconId = 0;
unsigned int Images::referenceIconId = 0;
unsigned int Images::conditionIconId = 0;
unsigned int Images::elseIconId = 0;
unsigned int Images::stepIconId = 0;
unsigned int Images::overrideIcondId = 0;
unsigned int Images::unionIconId = 0;
unsigned int Images::intersectionIconId = 0;
unsigned int Images::differenceIconId = 0;
unsigned int Images::keyIconId = 0;
unsigned int Images::useIconId = 0;
unsigned int Images::listIconId = 0;
unsigned int Images::creatorIconId = 0;
unsigned int Images::instanceOfIconId = 0;
unsigned int Images::readIconId = 0;
unsigned int Images::writeIconId = 0;
unsigned int Images::inPackageIconId = 0;
unsigned int Images::superAndSubIconId = 0;
unsigned int Images::graphIconId = 0;
unsigned int Images::instanceIconId = 0;
unsigned int Images::indexIcon = 0;

void Images::init() {
    int my_image_width = 0;
    int my_image_height = 0;
    unsigned int And = 0;
    unsigned int Plus = 0;
    unsigned int Minus = 0;
    unsigned int A = 0;
    unsigned int C = 0;
    unsigned int E = 0;
    unsigned int F = 0;
    unsigned int G = 0;
    unsigned int I = 0;
    unsigned int K = 0;
    unsigned int L = 0;
    unsigned int M = 0;
    unsigned int N = 0;
    unsigned int O = 0;
    unsigned int P = 0;
    unsigned int R = 0;
    unsigned int S = 0;
    unsigned int U = 0;
    unsigned int V = 0;
    unsigned int W = 0;

    if (not LoadTextureFromFile(FileManager::alphabetIconAndPath.data(), &And, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconAndPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconPlusPath.data(), &Plus, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconPlusPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconMinusPath.data(), &Minus, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconMinusPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconAPath.data(), &A, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconAPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconCPath.data(), &C, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconCPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconEPath.data(), &E, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconEPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconFPath.data(), &F, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconFPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconGPath.data(), &G, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconGPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconIPath.data(), &I, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconIPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconKPath.data(), &K, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconKPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconLPath.data(), &L, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconLPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconMPath.data(), &M, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconMPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconNPath.data(), &N, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconNPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconOPath.data(), &O, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconOPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconPPath.data(), &P, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconPPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconRPath.data(), &R, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconRPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconSPath.data(), &S, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconSPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconUPath.data(), &U, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconUPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconVPath.data(), &V, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconVPath.data());
    }
    if (not LoadTextureFromFile(FileManager::alphabetIconWPath.data(), &W, &my_image_width, &my_image_height)) {
        spdlog::get(ErrorManager::FileManagerTag)->warn("icon not found {}", FileManager::alphabetIconWPath.data());
    }

    unionIconId = Plus;
    intersectionIconId = And;
    differenceIconId = Minus;
    keyIconId = K;
    useIconId = U;
    classScopeIconId = C;
    fieldIconId = F;
    methodIconId = M;
    parameterIconId = P;
    varIconId = V;
    returnIconId = R;
    lineIconId = L;
    orderLineIconId = O;
    segmentLineIconId = S;
    anyIconId = A;
    referenceIconId = R;
    conditionIconId = C;
    elseIconId = E;
    stepIconId = S;
    overrideIcondId = O;
    listIconId = L;
    creatorIconId = C;
    instanceOfIconId = I;
    readIconId = R;
    writeIconId = W;
    inPackageIconId = P;
    superAndSubIconId = S;
    graphIconId = G;
    instanceIconId = I;
    indexIcon = I;
}
