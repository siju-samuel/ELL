////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     ReLUActivation.tcc (neural)
//  Authors:  Byron Changuion
//
////////////////////////////////////////////////////////////////////////////////////////////////////

namespace ell
{
namespace predictors
{
namespace neural
{
    template <typename ElementType>
    ElementType ReLUActivation<ElementType>::Apply(const ElementType input, const math::IntegerTriplet& /*index*/) const
    {
        return ((input > 0) ? input : 0);
    }
}
}
}
