/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "BLI_math_base.h"
#include "BLI_math_rotation.h"

#include "node_geometry_util.h"

static bNodeSocketTemplate geo_node_edge_split_in[] = {
    {SOCK_GEOMETRY, N_("Geometry")},
    {SOCK_FLOAT,
     N_("Angle"),
     DEG2RADF(30.0f),
     0.0f,
     0.0f,
     0.0f,
     0.0f,
     DEG2RADF(180.0f),
     PROP_ANGLE},
    {SOCK_BOOLEAN, N_("Sharp Edges")},
    {-1, ""},
};

static bNodeSocketTemplate geo_node_edge_split_out[] = {
    {SOCK_GEOMETRY, N_("Geometry")},
    {-1, ""},
};

void register_node_type_geo_edge_split()
{
  static bNodeType ntype;

  geo_node_type_base(&ntype, GEO_NODE_EDGE_SPLIT, "Edge Split", 0, 0);
  node_type_socket_templates(&ntype, geo_node_edge_split_in, geo_node_edge_split_out);
  nodeRegisterType(&ntype);
}