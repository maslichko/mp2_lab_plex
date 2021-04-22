#include <gtest.h>
#include <TPlex.h>

TEST(TPlex, creating_empty_plex) 
{
  ASSERT_NO_THROW(TPlex A);
}

TEST(TPlex, creating_non_empty_plex) 
{
	TPoint a(8, 13);
	TPoint b(25, 34);
	
  ASSERT_NO_THROW(TPlex q(&a, &b));
}


TEST(TPlex, adding_line_in_plex) 
{
	TPoint a(8, 13);
	TPoint b(25, 34);
	TPoint c(47, 54);

	TPlex q(&a, &b);
	
  ASSERT_NO_THROW(q.AddLine(&b, &c));
}

TEST(TLine, creating_line) 
{
	TPoint a(8, 13);
	TPoint b(25, 34);
  
  ASSERT_NO_THROW(TLine AB(a, b));
}

TEST(TSquare, creating_square) 
{
	TPoint a(8, 13);
	TPoint b(25, 34);
	TPoint c(47, 54);
	TPoint d(73, 92);

	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	ASSERT_NO_THROW(TSquare ABCD(AB, BC, CD, DA));
}

TEST(TCanvas, getting_empty_canvas)
{
	ASSERT_NO_THROW(TCanvas z);
}

TEST(TCanvas, getting_canvas_from_plex) 
{
	TPoint a(8, 13);
	TPoint b(25, 34);
	TPlex q(&a, &b);

	TCanvas z;
	ASSERT_NO_THROW(z.AddObj(&q));
}

TEST(TCanvas, getting_canvas_from_line)
{
	TPoint a(8, 13);
	TPoint b(25, 34);

	TLine AB(a, b);

	TCanvas z;
	ASSERT_NO_THROW(z.AddObj(&AB));
}

TEST(TCanvas, getting_canvas_from_point)
{
	TPoint a(8, 13);
	
	TCanvas z;
	ASSERT_NO_THROW(z.AddObj(&a));
}

TEST(TCanvas, getting_canvas_from_square)
{
	TPoint a(8, 13);
	TPoint b(25, 34);
	TPoint c(47, 54);
	TPoint d(73, 92);

	TLine AB(a, b);
	TLine BC(b, c);
	TLine CD(c, d);
	TLine DA(d, a);

	TSquare ABCD(AB, BC, CD, DA);

	TCanvas z;
	ASSERT_NO_THROW(z.AddObj(&ABCD));
}

TEST(Print, using_print_to_point)
{
	TPoint a(8, 13);
	ASSERT_NO_THROW(a.Print());
}

TEST(Print, using_print_to_plex)
{
	TPoint a(8, 13);
	TPoint b(25, 34);

	TPlex q(&a, &b);
	ASSERT_NO_THROW(q.Print());
}

TEST(Print, using_print_to_line)
{
	TPoint a(8, 13);
	TPoint b(25, 34);

	TLine l(a, b);
	ASSERT_NO_THROW(l.Print());
}

TEST(Print, using_print_all)
{
	TPoint a(8, 13);
	TPoint b(25, 34);

	TPlex q(&a, &b);
	ASSERT_NO_THROW(q.PrintAll());
}
