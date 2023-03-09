public enum ColorType {
	RESET, BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, GREY, ORANGE;

	public String	getColorCode()
	{
		switch (this) {
			case RESET:
				return ("\033[0m");
			case BLACK:
				return ("\033[30m");
			case RED:
				return ("\033[31m");
			case GREEN:
				return ("\033[32m");
			case YELLOW:
				return ("\033[33m");
			case BLUE:
				return ("\033[34m");
			case MAGENTA:
				return ("\033[35m");
			case CYAN:
				return ("\033[36m");
			case WHITE:
				return ("\033[37m");
			case GREY:
				return ("\033[0;48;2;80;80;80m");
			case ORANGE:
				return ("\033[0;48;2;255;129;0m");
		
			default:
				return (null);
		}
	}

	public String	toString()
	{
		switch (this) {
			case RESET:
				return (String.format("Reset\n"));
			case BLACK:
				return (String.format("Black\n"));
			case RED:
				return (String.format("Red\n"));
			case GREEN:
				return (String.format("Green\n"));
			case YELLOW:
				return (String.format("Yellow\n"));
			case BLUE:
				return (String.format("Blue\n"));
			case MAGENTA:
				return (String.format("Magenta\n"));
			case CYAN:
				return (String.format("Cyan\n"));
			case WHITE:
				return (String.format("White\n"));
			case GREY:
				return (String.format("Grey\n"));
			case ORANGE:
				return (String.format("Orange\n"));
		
			default:
				return (null);
		}
	}
}
