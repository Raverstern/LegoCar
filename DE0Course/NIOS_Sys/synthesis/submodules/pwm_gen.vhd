library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
--!needs an input as level counter from the avalon reg to form the pwm it decides the duty cycle
--!needs an period counter number it decides the frequency
--!for dead zone, the level counter should has upper lower limit
--!flow of control: set the duty cycle 1 and 2, set the period of pwm, then
--enable the module by asserting the saw_en signal to high and keep it
entity pwm_gen is

  -- generic (
    -- G_WIDTH : integer:= 32;
    -- G_reset_polarity : std_logic := '1'  -- active high reset
    -- );
  port(
    csi_I_clk: in std_logic;
    csi_I_rst: in std_logic;
    --!interface to Avalon
	avs_address: in std_logic_vector(2 downto 0);
	avs_write: in std_logic;
	avs_I_cs: in std_logic;
	avs_I_wr_data: in std_logic_vector(31 downto 0);
	coe_O_pwm1: out std_logic;
    coe_O_pwm2: out std_logic
    -- I_saw_en : in std_logic;
    -- I_period: in std_logic_vector(G_WIDTH-1 downto 0);
    -- I_duty1: in std_logic_vector(G_WIDTH-1 downto 0);
    -- I_duty2: in std_logic_vector(G_WIDTH-1 downto 0)
);
end pwm_gen;

architecture A_rtl of pwm_gen is
signal S_saw_cnt : unsigned(31 downto 0);  --!saw wave gen counter
signal S_period : unsigned(31 downto 0) ;  --!period of signal
signal S_duty1,S_duty2 : unsigned(31 downto 0) ;  --!duty cycle
 signal S_phase1,S_phase2: unsigned(31 downto 0);--!phase register


signal S_saw_en1,S_saw_en2 : std_logic ;          --! enable signal for generation

begin  -- A_rtl
--!triangle waveform gen
  process(csi_I_clk,csi_I_rst,S_saw_cnt,S_saw_en1,S_saw_en2)
    begin
      if rising_edge(csi_I_clk) then
        if csi_I_rst='0' then
          S_saw_cnt<=(others=>'0');
        else
          if S_saw_en1='1' or S_saw_en2='1' then
            if S_saw_cnt=S_period then
              S_saw_cnt<=(others=>'0');
            else
              S_saw_cnt<=S_saw_cnt+1;
            end if;
          end if;
        end if;
      end if;
  end process;
--!comparator duty1 and duty2 should not be the same as the deadzone exits
 coe_O_pwm1<='1' when (S_saw_cnt>S_phase1 and S_saw_cnt<S_phase1+S_duty1 and S_saw_en1='1') else
         '0' ;
 coe_O_pwm2<='1' when (S_saw_cnt<S_phase2+S_duty2 and S_saw_cnt>S_phase2 and S_saw_en2='1') else
       '0' ;
--!register
  -- process(csi_I_clk,csi_I_rst,I_period)
  -- begin
      -- if rising_edge(csi_I_clk) then
        -- if csi_I_rst=G_reset_polarity then
          -- S_period<=(others=>'0');
        -- else
          -- S_period<=I_period;
        -- end if;
      -- end if;
  -- end process;

  -- process(csi_I_clk,csi_I_rst,I_duty1)
  -- begin
      -- if rising_edge(csi_I_clk) then
        -- if csi_I_rst=G_reset_polarity then
          -- S_duty1<=(others=>'0');
        -- else
          -- S_duty1<=I_duty1;
        -- end if;
      -- end if;
  -- end process;

  -- process(csi_I_clk,csi_I_rst,I_duty2)
  -- begin
      -- if rising_edge(csi_I_clk) then
        -- if csi_I_rst=G_reset_polarity then
          -- S_duty2<=(others=>'0');
        -- else
          -- S_duty2<=I_duty2;
        -- end if;
      -- end if;
  -- end process;

  -- process(csi_I_clk,csi_I_rst,I_saw_en)
  -- begin
      -- if rising_edge(csi_I_clk) then
        -- if csi_I_rst=G_reset_polarity then
          -- S_saw_en<='0';
        -- else
          -- S_saw_en<=I_saw_en;
        -- end if;
      -- end if;
  -- end process;
--avalon interface
process(csi_I_clk,csi_I_rst,avs_address,avs_write,avs_I_cs,avs_I_wr_data)
begin
	if rising_edge(csi_I_clk) then
        if csi_I_rst='0' then
			S_saw_en1<='0';
			S_saw_en2<='0';
			S_period<=(others=>'0');
			S_duty1<=(others=>'0');
			S_duty2<=(others=>'0');
			S_phase1<=(others=>'0');
			S_phase2<=(others=>'0');
		else
			if avs_write='1' and avs_I_cs='1' then
				case avs_address is
				when "000"=> --enable register
					S_saw_en1<=avs_I_wr_data(0);
					S_saw_en2<=avs_I_wr_data(1);
				when "001"=> --period register
					S_period<=unsigned(avs_I_wr_data);
				when "010"=> --duty1 register
					S_duty1<=unsigned(avs_I_wr_data);
				when "011"=> --duty2 register
					S_duty2<=unsigned(avs_I_wr_data);
				when "100"=> --phase register
				    S_phase1<=unsigned(avs_I_wr_data);
				when "101"=>
				    S_phase2<=unsigned(avs_I_wr_data);
				when others=> null;
				end case;
			end if;
		end if;
	end if;
end process;

end A_rtl;
