#pragma once

// Suppress sscanf warning on MSVCCompiler
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <string>
#include <vector>
#include <map>
#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <chrono>

#include "triangle.hpp"
#include "envmap.hpp"
#include "math/float3.hpp"

using FireRays::float3;

class Scene {
public:
    Scene(const std::string filename);
    ~Scene();

    std::vector<RTTriangle> &getTriangles() { return triangles; }
    EnvironmentMap *getEnvMap() { return envmap; }

    std::string hashString();

private:
    void loadModel(const std::string filename); // load .obj or .ply model
    void loadObjModel(const std::string filename);
    void loadPlyModel(const std::string filename);

    void unpackIndexedData(const std::vector<float3> &positions,
                           const std::vector<float3>& normals,
                           const std::vector<std::array<unsigned, 6>>& faces,
                           bool type_ply);

  void computeHash(const std::string filename);

  EnvironmentMap *envmap = nullptr;
  std::vector<RTTriangle> triangles;
  size_t hash;
};
