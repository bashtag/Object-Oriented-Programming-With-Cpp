import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

public class driver1 {
	public static void main(String[] args) throws InterruptedException {
		Tetris	tetrisGame;
		int	rowSize = 0, colSize = 0, counter = 0;
		char	givenType;
		String	checkType = "IOTJLSZQR";
		boolean	isFinished = false;
		Scanner	scanner = new Scanner(System.in);

		/* to check inputs */
		while (true)
		{
			System.out.println("Enter the height of the tetris board: (it must be greater than 4)");
			try {
				rowSize = scanner.nextInt();
				if (rowSize < 4)
					throw new InputMismatchException();
				break;
			} catch (InputMismatchException e) {
				System.out.println("Give me a valid input");
				scanner.nextLine();
				continue;
			}
		}

		while (true)
		{
			System.out.println("Enter the weight of the tetris board: (it must be greater than 4)");
			try {
				colSize = scanner.nextInt();
				if (colSize < 4)
					throw new InputMismatchException();
				break;
			} catch (InputMismatchException e) {
				System.out.println("Give me a valid input");
				scanner.nextLine();
				continue;
			}
		}

		tetrisGame = new Tetris(rowSize, colSize);

		tetrisGame.printBoard();
		do
		{
			do
			{
				System.out.println("Give me a valid Tetromino Type (I, O, T, J, L, S, Z). R for random Tetromino, Q for quit.");
				givenType = scanner.next().toUpperCase().charAt(0);

				if (checkType.indexOf(givenType) == -1)
					System.out.println("Give me a valid type");
			} while (checkType.indexOf(givenType) == -1);

			if (givenType == 'R')
				givenType = tetrisGame.randomChType();
			
			if (!tetrisGame.isGameFinished(counter, givenType))
			{
				tetrisGame.clearScreen(tetrisGame.getColSize() + 5);
				System.out.print("\033[J"); /* Delete til the end of the terminal */
				tetrisGame.takeOneTetromino(givenType);
				tetrisGame.animate(counter);
				++counter;
			}
			else
				isFinished = true;
		} while (!isFinished && (tetrisGame.getBotTetColSize() != tetrisGame.getColSize()));
		
		System.out.println("Game is Finished!");

	}
}
