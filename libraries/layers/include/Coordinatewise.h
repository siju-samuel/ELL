////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     Coordinatewise.h (layers)
//  Authors:  Ofer Dekel
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Layer.h"
#include "CoordinateList.h"

// stl
#include <cstdint>
#include <vector>
#include <functional>
#include <string>

namespace layers
{
    /// <summary> A class that represents a layer that performs a coordinatewise operation. </summary>
    class Coordinatewise : public Layer
    {
    public:

        enum class OperationType {none, add, multiply};

        /// <summary> Constructs an instance of a Coordinatewise layer. </summary>
        ///
        /// <param name="operationType"> The type of Coordinatewise layer to construct. </param>
        Coordinatewise(OperationType operationType = OperationType::none);

        /// <summary> Constructs an instance of a Coordinatewise layer. </summary>
        ///
        /// <param name="values"> The value for each element. </param>
        /// <param name="coordinates"> The input coordinate for each element. </param>
        /// <param name="operationType"> The type of Coordinatewise layer to construct. </param>
        Coordinatewise(std::vector<double> values, CoordinateList coordinates, OperationType operationType);

        /// <summary> Returns the input dimension of the layer. </summary>
        ///
        /// <returns> The input dimension. </returns>
        virtual uint64_t GetInputDimension() const override;

        /// <summary> Returns the output dimension of the layer. </summary>
        ///
        /// <returns> The output dimension. </returns>
        virtual uint64_t GetOutputDimension() const override;

        /// <summary> Appends a coordinate to the coordinatewise layer. </summary>
        ///
        /// <param name="value"> The value to append. </param>
        /// <param name="coordinate"> The coordinate to append. </param>
        void Append(double value, Coordinate coordinate);

        static const std::string GetOperationName(OperationType type);
        static OperationType GetOperationType(const std::string& name);
        static std::function<double(double, double)> GetOperation(OperationType type);
        OperationType GetOperationType() const;

        /// <summary> Computes the layer output. </summary>
        ///
        /// <param name="inputs"> The set of vectors holding input values to use </param>
        /// <param name="outputs"> [out] The vector where the output values are written. </param>
        virtual void Compute(const std::vector<std::vector<double>>& inputs, std::vector<double>& outputs) const override;

        /// <summary> Returns an iterator that enumerates the input coordinates for a specified element. </summary>
        ///
        /// <param name="index"> Zero-based element index. </param>
        ///
        /// <returns> The input coordinates. </returns>
        virtual CoordinateIterator GetInputCoordinateIterator(uint64_t index) const override;

        /// <summary> Returns the minimal required size of an input layer, which is the maximum input element from that layer plus 1. </summary>
        ///
        /// <param name="layerindex"> The layer index. </param>
        ///
        /// <returns> The required layer size. </returns>
        virtual uint64_t GetRequiredLayerSize(uint64_t layerIndex) const override;

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        static std::string GetTypeName();

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        virtual std::string GetRuntimeTypeName() const override;

        /// <summary> Reads the layer from an XMLDeserializer. </summary>
        ///
        /// <param name="deserializer"> [in,out] The deserializer. </param>
        virtual void Read(utilities::XMLDeserializer& deserializer) override;

        /// <summary> Writes the layer to an XMLSerializer. </summary>
        ///
        /// <param name="serializer"> [in,out] The serializer. </param>
        virtual void Write(utilities::XMLSerializer& serializer) const override;

    protected:
        std::vector<double> _values;
        CoordinateList _inputCoordinates;
        OperationType _operationType;
        static const int _currentVersion = 1;
    };
}
