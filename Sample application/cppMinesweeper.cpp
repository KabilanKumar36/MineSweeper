#include "cppMinesweeper.h"

wxBEGIN_EVENT_TABLE(cppMinesweeper, wxFrame)
wxEND_EVENT_TABLE()

cppMinesweeper::cppMinesweeper() : wxFrame(nullptr, wxID_ANY, "Mine Sweeper", wxPoint(20, 20), wxSize(1500, 800))
{
	btn = new wxButton * [width * height];
	wxGridSizer* grid = new wxGridSizer(width, height, 0, 0);

	field = new int[width * height];

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			btn[j * width + i] = new wxButton(this, 10000 + (j * width + i));
			btn[j * width + i]->SetFont(font);
			grid->Add(btn[j * width + i], 1, wxEXPAND | wxALL);

			btn[j * width + i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cppMinesweeper::OnbuttonClicked, this);
			field[j * width + i] = 0;
		}
	}
	this->SetSizer(grid);
	grid->Layout();

}

cppMinesweeper::~cppMinesweeper()
{
	delete[] btn;
}

void cppMinesweeper::OnbuttonClicked(wxCommandEvent& evt)
{
	/*m_lst1->AppendString(m_txt1->GetValue());
	evt.Skip();
	*/
	int x = (evt.GetId() - 10000) % width;
	int y = (evt.GetId() - 10000) / width;
	if (firstclick)
	{
		int mines = 30;
		while (mines)
		{
			int rx = rand() % width;
			int ry = rand() % height;
			if (field[ry * width + rx] == 0 && rx != x && ry != y)
			{
				field[ry * width + rx] = -1;
				mines--;
			}
		}
		firstclick = false;
	}


	btn[y * width + x]->Enable(false);

	if (field[y * width + x] == -1)
	{
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				if (field[j * width + i] == -1)
				{
					btn[j * width + i]->SetLabel("_-_");
				}
			}
		}
		wxMessageBox("Game over!");
		firstclick = true;
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				field[j * width + i] = 0;
				btn[j * width + i]->SetLabel("");
				btn[j * width + i]->Enable(true);
			}
		}
	}
	else
	{
		int mine_count = 0;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height)
				{
					if (field[(y + j) * width + (x + i)] == -1)
						mine_count++;
				}
			}
		}

		if (mine_count > 0)
		{
			btn[y * width + x]->SetLabel(std::to_string(mine_count));
		}
	}
}