#ifndef __GF2_SCHNABELENV_H__
#define __GF2_SCHNABELENV_H__

#include <vector>
#include "pcl/point_cloud.h"
#include "globfit2/my_types.h"

namespace GF2
{
    //class PlanePrimitive;

    class SchnabelEnv
    {
        public:
            template <class PclCloudT, typename PrimitiveT, class PidGidT, class PointContainerT >
            static inline int
            run( std::vector<PrimitiveT>    &planes
                 , PidGidT                  &pidGid
                 , PointContainerT          &points
                 , typename PclCloudT::Ptr  &cloud
                 , float scale = 0.01
                 , int                                 min_support_arg = 300
                 , int show = 1 );
    };

} // ns am

#endif // SCHNABELENV_H
