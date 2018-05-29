/* Copyright (c) 2015-2018, EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
 * Responsible Author: Cyrille Favreau <cyrille.favreau@epfl.ch>
 *
 * This file is part of Brayns <https://github.com/BlueBrain/Brayns>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef RENDERINGPARAMETERS_H
#define RENDERINGPARAMETERS_H

#include <brayns/common/types.h>

#include "AbstractParameters.h"

SERIALIZATION_ACCESS(RenderingParameters)

namespace brayns
{
class AbstractParameters;

/** Manages rendering parameters
 */
class RenderingParameters : public AbstractParameters
{
public:
    RenderingParameters();

    /** @copydoc AbstractParameters::print */
    void print() final;

    /** Engine*/
    EngineType getEngine() const { return _engine; }
    void setEngine(const EngineType name) { _updateValue(_engine, name); }
    const std::string& getEngineAsString(const EngineType value) const;
    /** OSPRay module */
    const std::string& getModule() const { return _module; }
    /** OSPRay renderer */
    void initializeDefaultRenderers();
    RendererType getRenderer() const { return _renderer; }
    const std::string& getRendererAsString(const RendererType value) const;
    void setRenderer(const RendererType renderer)
    {
        _updateValue(_renderer, renderer);
    }
    /** OSPRay supported renderers */
    const RendererTypes& getRenderers() const { return _renderers; }
    /** Shadows */
    float getShadows() const { return _shadows; }
    void setShadows(const float value) { _updateValue(_shadows, value); }
    /** Softs Shadows generated by randomizing light source position */
    float getSoftShadows() const { return _softShadows; }
    void setSoftShadows(const float value)
    {
        _updateValue(_softShadows, value);
    }
    /** Ambient occlusion */
    float getAmbientOcclusionStrength() const
    {
        return _ambientOcclusionStrength;
    }
    void setAmbientOcclusionStrength(const float value)
    {
        _updateValue(_ambientOcclusionStrength, value);
    }
    float getAmbientOcclusionDistance() const
    {
        return _ambientOcclusionDistance;
    }
    void setAmbientOcclusionDistance(const float value)
    {
        _updateValue(_ambientOcclusionDistance, value);
    }

    /** Shading applied to the geometry
     */
    ShadingType getShading() const { return _shading; }
    const std::string& getShadingAsString(const ShadingType value) const;
    void setShading(const ShadingType value) { _updateValue(_shading, value); }
    /** Number of samples per pixel */
    int getSamplesPerPixel() const { return _spp; }
    void setSamplesPerPixel(const int value) { _updateValue(_spp, value); }
    /** Enables photon emission according to the radiance value of the
     * material */
    bool getLightEmittingMaterials() const { return _lightEmittingMaterials; }
    void setLightEmittingMaterials(const bool value)
    {
        _updateValue(_lightEmittingMaterials, value);
    }

    bool getDynamicLoadBalancer() const { return _dynamicLoadBalancer; }
    void setDynamicLoadBalancer(const bool value)
    {
        _updateValue(_dynamicLoadBalancer, value);
    }

    const Vector3f& getBackgroundColor() const { return _backgroundColor; }
    void setBackgroundColor(const Vector3f& value)
    {
        _updateValue(_backgroundColor, value);
    }
    /**
       Defines the maximum distance between intersection and surrounding
       geometry for touch detection rendering
    */
    float getDetectionDistance() const { return _detectionDistance; }
    void setDetectionDistance(const float value)
    {
        _updateValue(_detectionDistance, value);
    }
    /**
       Defines if touch detection applies if the material of the surrounding
       geometry is different from the one of the intersection
    */
    bool getDetectionOnDifferentMaterial() const
    {
        return _detectionOnDifferentMaterial;
    }
    void setDetectionOnDifferentMaterial(const bool value)
    {
        _updateValue(_detectionOnDifferentMaterial, value);
    }

    /**
       Near color used by touch detection renderer
    */
    const Vector3f& getDetectionNearColor() const
    {
        return _detectionNearColor;
    }
    void setDetectionNearColor(const Vector3f& value)
    {
        _updateValue(_detectionNearColor, value);
    }

    /**
       Far color used by touch detection renderer
    */
    const Vector3f& getDetectionFarColor() const { return _detectionFarColor; }
    void setDetectionFarColor(const Vector3f& value)
    {
        _updateValue(_detectionFarColor, value);
    }

    /**
        Raytracers have to deal with the finite precision of computer
        calculations. Since the origin of the reflected ray lies on the surface
        of the object, there will be an intersection point at zero distance.
        Since we do not want that, all intersection distances less than the
        epsilon value are ignored.
     */
    float getEpsilon() const { return _epsilon; }
    void setEpsilon(const float epsilon) { _updateValue(_epsilon, epsilon); }
    /**
       Camera type
    */
    void initializeDefaultCameras();
    CameraType getCameraType() const { return _cameraType; }
    const std::string& getCameraTypeAsString(const CameraType value) const;
    StereoMode getStereoMode() const { return _stereoMode; }
    const std::string& getStereoModeAsString(const StereoMode value) const;

    /**
       Epsilon. All intersection distances less than the epsilon value are
       ignored by the raytracer.
    */
    void setEpsilon(const CameraType cameraType)
    {
        _updateValue(_cameraType, cameraType);
    }
    /**
       Light source follow camera origin
    */
    bool getHeadLight() const { return _headLight; }
    /** If the rendering should be refined by accumulating multiple passes */
    bool getAccumulation() const { return _accumulation; }
    /**
     * @return the threshold where accumulation stops if the variance error
     * reaches this value.
     */
    float getVarianceThreshold() const { return _varianceThreshold; }
    /**
     * The threshold where accumulation stops if the variance error reaches this
     * value.
     */
    void setVarianceThreshold(const float value)
    {
        _updateValue(_varianceThreshold, value);
    }

    /**
     * The maximum number of accumulation frames before engine signals to stop
     * continuation of rendering.
     *
     * @sa Engine::continueRendering()
     */
    void setMaxAccumFrames(const size_t value)
    {
        _updateValue(_maxAccumFrames, value);
    }
    size_t getMaxAccumFrames() const { return _maxAccumFrames; }
    /**
     * @brief Defines the number of samples per ray for ray-casting rendering
     * (typically volumes)
     * @param spr Number of samples per ray
     */
    void setSamplesPerRay(const size_t spr) { _updateValue(_spr, spr); }
    size_t getSamplesPerRay() const { return _spr; }
protected:
    void parse(const po::variables_map& vm) final;

    EngineType _engine{EngineType::ospray};
    std::string _module;
    RendererType _renderer{RendererType::default_};
    RendererTypes _renderers;
    strings _rendererNames;
    CameraType _cameraType{CameraType::default_};
    StereoMode _stereoMode{StereoMode::none};
    strings _cameraTypeNames;
    float _ambientOcclusionStrength{0.f};
    float _ambientOcclusionDistance{1.2f};
    ShadingType _shading{ShadingType::diffuse};
    bool _lightEmittingMaterials{false};
    int _spp{1};
    bool _accumulation{true};
    float _shadows{0.f};
    float _softShadows{0.f};
    Vector3f _backgroundColor{0.f, 0.f, 0.f};
    float _detectionDistance{1.f};
    bool _detectionOnDifferentMaterial{true};
    Vector3f _detectionNearColor{1.f, 0.f, 0.f};
    Vector3f _detectionFarColor{0.f, 1.f, 0.f};
    float _epsilon{0.f};
    bool _headLight{false};
    bool _dynamicLoadBalancer{false};
    float _varianceThreshold{-1.f};
    size_t _maxAccumFrames{100};
    size_t _spr{128};

    SERIALIZATION_FRIEND(RenderingParameters)
};
}
#endif // RENDERINGPARAMETERS_H
