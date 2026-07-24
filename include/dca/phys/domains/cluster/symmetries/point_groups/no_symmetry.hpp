// Copyright (C) 2018 ETH Zurich
// Copyright (C) 2018 UT-Battelle, LLC
// All rights reserved.
//
// See LICENSE for terms of usage.
// See CITATION.md for citation guidelines, if DCA++ is used for scientific publications.
//
// Author: Peter Staar (taa@zurich.ibm.com)
//
// No symmetry.

#ifndef DCA_PHYS_DOMAINS_CLUSTER_SYMMETRIES_POINT_GROUPS_NO_SYMMETRY_HPP
#define DCA_PHYS_DOMAINS_CLUSTER_SYMMETRIES_POINT_GROUPS_NO_SYMMETRY_HPP

#include <type_traits>

#include "dca/phys/domains/cluster/symmetries/symmetry_operations/identity_group_operation.hpp"
#include "dca/util/type_list.hpp"

namespace dca {
namespace phys {
namespace domains {
// dca::phys::domains::

template <int DIMENSION>
struct no_symmetry {
  static constexpr int DIM = DIMENSION;
  typedef dca::util::Typelist<identity_group_operation<DIMENSION>> point_group_type_list;
};

// True iff PointGroup is no_symmetry<D>. Under derive-authoritative symmetrization a no_symmetry
// declaration is the honored exception: it routes the model to the legacy (declared, identity-only)
// path, i.e. it is the permanent "symmetrization off" switch. Every other declaration is ignored
// for in-scope models in favor of the H0-derived group.
template <typename PointGroup>
struct is_no_symmetry : std::false_type {};
template <int DIMENSION>
struct is_no_symmetry<no_symmetry<DIMENSION>> : std::true_type {};

}  // domains
}  // phys
}  // dca

#endif  // DCA_PHYS_DOMAINS_CLUSTER_SYMMETRIES_POINT_GROUPS_NO_SYMMETRY_HPP
