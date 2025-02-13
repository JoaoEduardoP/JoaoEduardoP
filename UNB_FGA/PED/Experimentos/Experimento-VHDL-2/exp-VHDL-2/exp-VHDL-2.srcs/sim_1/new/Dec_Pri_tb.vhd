library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity Dec_Pri_tb is
end Dec_Pri_tb;

architecture Behavioral of Dec_Pri_tb is

    component Dec_Pri is
        Port ( p0 : in STD_LOGIC;
               p1 : in STD_LOGIC;
               p2 : in STD_LOGIC;
               p3 : in STD_LOGIC;
               x1 : out STD_LOGIC;
               x0 : out STD_LOGIC;
               int : out STD_LOGIC);
    end component;

    signal s0,s1,s2,s3, ss1, ss2, ss3: STD_LOGIC:='0';

begin

    uut: Dec_Pri port map(
    p0 => s0,
    p1 => s1,
    p2 => s2,
    p3 => s3,
    x1 => ss1,
    x0 => ss2,
    int => ss3);


    s0 <= '0', '0' after 50 ns, '0' after 100 ns, '0' after 150 ns, '0' after 200 ns, '0' after 250 ns, '0' after 300 ns, '0' after 350 ns, '1' after 400 ns, '1' after 450 ns, '1' after 500 ns, '1' after 550 ns, '1' after 600 ns, '1' after 650 ns, '1' after 700 ns, '1' after 750 ns;
    s1 <= '0', '0' after 50 ns, '0' after 100 ns, '0' after 150 ns, '1' after 200 ns, '1' after 250 ns, '1' after 300 ns, '1' after 350 ns, '0' after 400 ns, '0' after 450 ns, '0' after 500 ns, '0' after 550 ns, '1' after 600 ns, '1' after 650 ns, '1' after 700 ns, '1' after 750 ns;
    s2 <= '0', '0' after 50 ns, '1' after 100 ns, '1' after 150 ns, '0' after 200 ns, '0' after 250 ns, '1' after 300 ns, '1' after 350 ns, '0' after 400 ns, '0' after 450 ns, '1' after 500 ns, '1' after 550 ns, '0' after 600 ns, '0' after 650 ns, '1' after 700 ns, '1' after 750 ns;
    s3 <= '0', '1' after 50 ns, '0' after 100 ns, '1' after 150 ns, '0' after 200 ns, '1' after 250 ns, '0' after 300 ns, '1' after 350 ns, '0' after 400 ns, '1' after 450 ns, '0' after 500 ns, '1' after 550 ns, '0' after 600 ns, '1' after 650 ns, '0' after 700 ns, '1' after 750 ns;
end Behavioral;
