//------------------------------------------------------------------------------//
// Author:                Starukhin Danila M.
// Author's e-mail:       sniperusus2002@gmail.com
// -----------------------------------------------------------------------------//
// Purpose: Edge Detector for signals
// Date: 2026/06
//------------------------------------------------------------------------------//


module edge_detector
    import edge_detector_pkg::edge_catch_type_e;
    // Types of catches
    import edge_detector_pkg::EDGE_CATCH_T_NONE;
    import edge_detector_pkg::EDGE_CATCH_T_RE;
    import edge_detector_pkg::EDGE_CATCH_T_FE;
    import edge_detector_pkg::EDGE_CATCH_T_BOTH;
#(
    parameter edge_catch_type_e ED_CATCH_T       = EDGE_CATCH_T_NONE,
    parameter logic             DEF_PREV_SIG_VAL = 0
) (
    /*============================### COMMON SIGNALS ###========================*/
    input  logic                clk,    // clk
    input  logic                rst_n,  // reset active
    input  logic                sig,
    output logic                sig_edge
    /*==========================================================================*/
);
    if(ED_CATCH_T == EDGE_CATCH_T_NONE) begin: g_no_catch
        assign sig_edge = DEF_PREV_SIG_VAL;
    end
    else begin: g_catch
        // gen signal with delay 1
        logic sig_d1;
        always_ff @(posedge clk or negedge rst_n) begin
            if (~rst_n)
                sig_d1 <= DEF_PREV_SIG_VAL;
            else
                sig_d1 <= sig;
        end

        case (ED_CATCH_T)
            EDGE_CATCH_T_RE:    begin: g_re_catch
                assign sig_edge =   sig  && (~sig_d1);
            end
            EDGE_CATCH_T_FE:    begin: g_le_catch
                assign sig_edge = (~sig) &&   sig_d1;
            end
            EDGE_CATCH_T_BOTH:  begin: g_both_catch
                assign sig_edge =   sig  !=   sig_d1;
            end
            default:            begin: g_err_catch
                assign sig_edge = DEF_PREV_SIG_VAL;
            end
        endcase

    end
endmodule
