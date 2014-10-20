#ifndef __GF2_CANDIDATEGENERATOR_H__
#define __GF2_CANDIDATEGENERATOR_H__

#include "globfit2/parameters.h"                         // CandidateGeneratorParams

namespace GF2
{
    class CandidateGenerator
    {
        public:
             /*! \brief                  Step 1. Generates primitives from a cloud. Reads "cloud.ply" and saves "candidates.csv".
              *  \param argc             Contains --cloud cloud.ply, and --scale scale.
              *  \param argv             Contains --cloud cloud.ply, and --scale scale.
              *  \return                 EXIT_SUCCESS.
              */
            template < class    _PrimitiveContainerT
                     , class    _PointContainerT
                     , typename _Scalar
                     , class    _PointPrimitiveT
                     , class    _PrimitiveT
                     >
            static inline int
            generateCli( int argc, char** argv );

            /*! \brief Main functionality to generate lines from points.
             *
             *  \tparam _PointPrimitiveDistanceFunctorT Concept: \ref MyPointPrimitiveDistanceFunctor.
             *  \tparam _PrimitiveT                     Concept: \ref GF2::LinePrimitive2.
             *  \param[in] smallThresh Decides, what primitive counts as small. Usually a multiple of scale (4x...0.1x)
             *  \post Produces primitives with STATUS tag UNSET(-1) (new primitives) or ACTIVE(2) (previously selected primitives)
             */
            template <  class       PrimitivePrimitiveAngleFunctorT // concept: energyFunctors.h::PrimitivePrimitiveAngleFunctor
                      , class       _PointPrimitiveDistanceFunctorT
                      , class       _PrimitiveT
                      , class       PrimitiveContainerT             // concept: std::vector<std::vector<LinePrimitive2>>
                      , class       PointContainerT                 // concept: std::vector<PointPrimitive>
                      , typename    Scalar
                      >
            static inline int
            generate( PrimitiveContainerT                   &  out_lines
                    , PrimitiveContainerT                   &  in_lines // non-const, because some of the primitives are promoted
                    , PointContainerT                  const&  points
                    , Scalar                           const   scale
                    , std::vector<Scalar>              const&  angles
                    , CandidateGeneratorParams<Scalar> const&  params
                    , Scalar                           const  smallThresh
                    , bool                             const  safe_mode = false );

    }; //...class CandidateGenerator
} // ...ns::GF2

#include "globfit2/optimization/impl/candidateGenerator.hpp"


#endif // __GF2_CANDIDATEGENERATOR_H__

