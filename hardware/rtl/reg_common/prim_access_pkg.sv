//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: pkg prim access
// Date: 2026/06
//------------------------------------------------------------------------------//

package prim_access_pkg;

    function automatic logic get_we_of_bit(
        input f_access_type_e access_type,
        input logic           swe
    );
        case (access_type)
            F_ACCESS_RW:
                return swe;
            F_ACCESS_WO:
                return swe;
            F_ACCESS_RO:
                return '1;
            F_ACCESS_W1S:
                return '1;
            default:
                return '0;
        endcase
    endfunction

    function automatic logic get_wd_of_bit(
        input f_access_type_e access_type,
        input logic           swd,//          = '0,
        input logic           hwd //          = '0
    );
        case (access_type)
            F_ACCESS_RW:
                return swd;
            F_ACCESS_WO:
                return swd;
            F_ACCESS_RO:
                return hwd;
            F_ACCESS_W1S:
                return hwd;
            default:
                return '0;
        endcase
    endfunction

endpackage
