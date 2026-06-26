//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Edge detector package
// Date: 2026/06
//------------------------------------------------------------------------------//

package edge_detector_pkg;

    parameter int unsigned EDGE_TYPE_W = 2;
    typedef enum logic [EDGE_TYPE_W - 1: 0] {
        EDGE_CATCH_T_NONE = (EDGE_TYPE_W)'(0),
        EDGE_CATCH_T_RE   = (EDGE_TYPE_W)'(1),
        EDGE_CATCH_T_FE   = (EDGE_TYPE_W)'(2),
        EDGE_CATCH_T_BOTH = (EDGE_TYPE_W)'(3)
    } edge_catch_type_e;

endpackage
