library ieee;
use ieee.std_logic_1164.all;

entity ULA is
    port (
        A     : in  std_logic_vector(3 downto 0);
        B     : in  std_logic_vector(3 downto 0);
        S     : in  std_logic_vector(1 downto 0);
        F     : out std_logic_vector(3 downto 0);
        over  : out std_logic;
        c_out : out std_logic
    );
end ULA;

architecture Behavioral of ULA is
    signal sum_result : std_logic_vector(3 downto 0); -- Resultado da soma com carry
    signal sub_result : std_logic_vector(3 downto 0); -- Resultado da subtração com carry
    
    signal and_result : std_logic_vector(3 downto 0); 
    signal or_result  : std_logic_vector(3 downto 0); 
    
    signal carry_sum  : std_logic_vector(3 downto 0); -- Para soma/subtração bit a bit
    signal carry_sub  : std_logic_vector(3 downto 0); -- Para soma/subtração bit a bit
    
    signal over_sum   : std_logic; 
    signal over_sub   : std_logic; 
begin
    -- Operação AND bit a bit
    and_result <= A and B;
    
    -- Operação OR bit a bit
    or_result <= A or B;

    -- Soma bit a bit (S = "00")
    sum_result(0) <= A(0) xor B(0);
    carry_sum(0)      <= A(0) and B(0);

    sum_result(1) <= A(1) xor B(1) xor carry_sum(0);
    carry_sum(1)      <= (A(1) and B(1)) or ((A(1) xor B(1)) and carry_sum(0));

    sum_result(2) <= A(2) xor B(2) xor carry_sum(1);
    carry_sum(2)      <= (A(2) and B(2)) or ((A(2) xor B(2)) and carry_sum(1));

    sum_result(3) <= A(3) xor B(3) xor carry_sum(2);
    carry_sum(3)      <= (A(3) and B(3)) or ((A(3) xor B(3)) and carry_sum(2));

    -- Subtração bit a bit (S = "01")
    sub_result(0) <= A(0) xor (not B(0)) xor '1';
    carry_sub(0)      <= (A(0) and (not B(0))) or (A(0) and '1') or ((not B(0)) and '1');
                        
    sub_result(1) <= A(1) xor (not B(1)) xor carry_sub(0);
    carry_sub(1)      <= (A(1) and (not B(1))) or (A(1) and carry_sub(0)) or ((not B(1)) and carry_sub(0));

    sub_result(2) <= A(2) xor (not B(2)) xor carry_sub(1);
    carry_sub(2)      <= (A(2) and (not B(2))) or (A(2) and carry_sub(1)) or ((not B(2)) and carry_sub(1));

    sub_result(3) <= A(3) xor (not B(3)) xor carry_sub(2);
    carry_sub(3)      <= (A(3) and (not B(3))) or (A(3) and carry_sub(2)) or ((not B(3)) and carry_sub(2));
    
    -- over
    over_sum <= (A(3) and B(3) and (not sum_result(3))) or 
                    ((not A(3)) and (not B(3)) and sum_result(3));
    
    over_sub <= (A(3) and (not B(3)) and (not sub_result(3))) or 
                   ((not A(3)) and B(3) and sub_result(3));

    -- Seleção da operação
    With S select
        F <= sum_result when "00",
             sub_result when "01",
             and_result when "10",
             or_result  when others;
 
    with S select
        over <= over_sum when "00",
                over_sub when "01",
                '0' when others;
    
    with S select
        c_out <= carry_sum(3) when "00", 
                 carry_sub(3) when "01",
                '0' when others;
    
end Behavioral;