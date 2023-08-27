#pragma once
#using <System.dll>
#include <string>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <array>
#include <iostream>
#include <iomanip>
#include <cliext/vector>
#include <chrono>
#include <thread>
#include "Date.h"
#include "SearchResults.h"
#include <algorithm>






namespace Search {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;
	using namespace System::Diagnostics;
	using namespace std;



	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ defaultSearchDatesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fromOneMonthAgoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toOneWeekRangeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fileNamesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ m552ToolStripMenuItem;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->defaultSearchDatesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fromOneMonthAgoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toOneWeekRangeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileNamesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->m552ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->label1->Location = System::Drawing::Point(12, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Search For";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(136, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(247, 37);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->label2->Location = System::Drawing::Point(12, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"File Name";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(136, 76);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(247, 37);
			this->textBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->label3->Location = System::Drawing::Point(12, 117);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 29);
			this->label3->TabIndex = 4;
			this->label3->Text = L"From";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->label4->Location = System::Drawing::Point(12, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 29);
			this->label4->TabIndex = 5;
			this->label4->Text = L"To";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dateTimePicker1->CalendarFont = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->CustomFormat = L"MMddyyyy";
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(84, 119);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(217, 27);
			this->dateTimePicker1->TabIndex = 6;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker1_ValueChanged);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dateTimePicker2->CalendarFont = (gcnew System::Drawing::Font(L"Calibri", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker2->CustomFormat = L"MMddyyyy";
			this->dateTimePicker2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker2->Location = System::Drawing::Point(84, 152);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(217, 27);
			this->dateTimePicker2->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::LightBlue;
			this->button1->FlatAppearance->BorderSize = 6;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->button1->Location = System::Drawing::Point(310, 119);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 62);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar1->Location = System::Drawing::Point(17, 187);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(447, 23);
			this->progressBar1->TabIndex = 10;
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 19;
			this->listBox1->Location = System::Drawing::Point(17, 235);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(447, 232);
			this->listBox1->TabIndex = 11;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::Color::LightBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->button2->Location = System::Drawing::Point(244, 528);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(220, 40);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Open File";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button3->BackColor = System::Drawing::Color::LightBlue;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->button3->Location = System::Drawing::Point(17, 528);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(220, 40);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Save Search";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackColor = System::Drawing::Color::LightBlue;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->button4->Location = System::Drawing::Point(244, 770);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(220, 39);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Load Search";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// listBox2
			// 
			this->listBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 19;
			this->listBox2->Location = System::Drawing::Point(17, 584);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(447, 156);
			this->listBox2->TabIndex = 15;
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button5->BackColor = System::Drawing::Color::LightPink;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Maroon;
			this->button5->Location = System::Drawing::Point(17, 769);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(220, 40);
			this->button5->TabIndex = 16;
			this->button5->Text = L"Delete Search";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->defaultSearchDatesToolStripMenuItem,
					this->fileNamesToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(481, 27);
			this->menuStrip1->TabIndex = 17;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// defaultSearchDatesToolStripMenuItem
			// 
			this->defaultSearchDatesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fromOneMonthAgoToolStripMenuItem,
					this->toOneWeekRangeToolStripMenuItem
			});
			this->defaultSearchDatesToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->defaultSearchDatesToolStripMenuItem->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->defaultSearchDatesToolStripMenuItem->Name = L"defaultSearchDatesToolStripMenuItem";
			this->defaultSearchDatesToolStripMenuItem->Size = System::Drawing::Size(106, 23);
			this->defaultSearchDatesToolStripMenuItem->Text = L"Search Dates";
			// 
			// fromOneMonthAgoToolStripMenuItem
			// 
			this->fromOneMonthAgoToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->fromOneMonthAgoToolStripMenuItem->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->fromOneMonthAgoToolStripMenuItem->Name = L"fromOneMonthAgoToolStripMenuItem";
			this->fromOneMonthAgoToolStripMenuItem->Size = System::Drawing::Size(194, 22);
			this->fromOneMonthAgoToolStripMenuItem->Text = L"From: One Month Ago";
			this->fromOneMonthAgoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fromOneMonthAgoToolStripMenuItem_Click);
			// 
			// toOneWeekRangeToolStripMenuItem
			// 
			this->toOneWeekRangeToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->toOneWeekRangeToolStripMenuItem->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->toOneWeekRangeToolStripMenuItem->Name = L"toOneWeekRangeToolStripMenuItem";
			this->toOneWeekRangeToolStripMenuItem->Size = System::Drawing::Size(194, 22);
			this->toOneWeekRangeToolStripMenuItem->Text = L"To: One Week Range";
			this->toOneWeekRangeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::toOneWeekRangeToolStripMenuItem_Click);
			// 
			// fileNamesToolStripMenuItem
			// 
			this->fileNamesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->m552ToolStripMenuItem,
					this->toolStripMenuItem2
			});
			this->fileNamesToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fileNamesToolStripMenuItem->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->fileNamesToolStripMenuItem->Name = L"fileNamesToolStripMenuItem";
			this->fileNamesToolStripMenuItem->Size = System::Drawing::Size(93, 23);
			this->fileNamesToolStripMenuItem->Text = L"File Names";
			// 
			// m552ToolStripMenuItem
			// 
			this->m552ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->m552ToolStripMenuItem->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->m552ToolStripMenuItem->Name = L"m552ToolStripMenuItem";
			this->m552ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->m552ToolStripMenuItem->Text = L"M552";
			this->m552ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::m552ToolStripMenuItem_Click);
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->label5->Location = System::Drawing::Point(17, 213);
			this->label5->MaximumSize = System::Drawing::Size(447, 19);
			this->label5->MinimumSize = System::Drawing::Size(447, 19);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(447, 19);
			this->label5->TabIndex = 18;
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button6->BackColor = System::Drawing::Color::LightBlue;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->button6->Location = System::Drawing::Point(244, 473);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(220, 40);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Search Results";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(17, 476);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(220, 37);
			this->textBox3->TabIndex = 20;
			// 
			// button7
			// 
			this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button7->BackColor = System::Drawing::Color::LightBlue;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->button7->Location = System::Drawing::Point(389, 33);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 37);
			this->button7->TabIndex = 21;
			this->button7->Text = L"AND";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button8->BackColor = System::Drawing::Color::LightBlue;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->button8->Location = System::Drawing::Point(389, 76);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 37);
			this->button8->TabIndex = 22;
			this->button8->Text = L"OR";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Bold));
			this->toolStripMenuItem2->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(180, 22);
			this->toolStripMenuItem2->Text = L"3981";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(481, 821);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"FileSearch";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: cli::array<Int32^>^ dTimeConvert(String^ t_aDate){
		Int32^ dateYear = (t_aDate[4] - 48) * 1000 + (t_aDate[5] - 48) * 100 + (t_aDate[6] - 48) * 10 + t_aDate[7] - 48;
		Int32^ dateMonth = (t_aDate[0] - 48) * 10 + t_aDate[1] - 48;
		Int32^ dateDay = (t_aDate[2] - 48) * 10 + t_aDate[3] - 48;
		cli::array<Int32^>^ myDate = { dateYear, dateMonth, dateDay };
		return myDate;
	}
	
	public: void loadDate(String^ t_searchTerm, String^ t_fileLocation, String^ t_fromDate, String^ t_toDate) {
			textBox1->Text = t_searchTerm;
			textBox2->Text = t_fileLocation;

			//dateTimePicker1->Value = Convert::ToDateTime(cli::array^dTimeConvert(t_fromDate));
			//dateTimePicker2->Value = Convert::ToDateTime(dTimeConvert(t_toDate));
			dateTimePicker2->Value = DateTime((t_toDate[4] - 48) * 1000 + (t_toDate[5] - 48) * 100 + (t_toDate[6] - 48) * 10 + t_toDate[7] - 48, (t_toDate[0] - 48) * 10 + t_toDate[1] - 48, (t_toDate[2] - 48) * 10 + t_toDate[3] - 48);
			dateTimePicker1->Value = DateTime((t_fromDate[4] - 48) * 1000 + (t_fromDate[5] - 48) * 100 + (t_fromDate[6] - 48) * 10 + t_fromDate[7] - 48, (t_fromDate[0] - 48) * 10 + t_fromDate[1] - 48, (t_fromDate[2] - 48) * 10 + t_toDate[3] - 48);
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		label5->Text = "Loading....";
		label5->Refresh();
		ClearSearchResults();
		progressBar1->Value = 0;
		listBox1->Items->Clear();
		if (textBox2->Text == "") {
			MessageBox::Show("This Could Take Awhile \n Please Pick a File Name \n to Search Faster. \n Progress Bar Won't Accurately Reflect Progress");
		}
		if (dateTimePicker1->Value > dateTimePicker2->Value) {
			MessageBox::Show("Changed 'To' Date to One \n After 'From' Date");
			DateTime fromDate = dateTimePicker1->Value;
			DateTime oneDayLater = fromDate.AddDays(1);
			dateTimePicker2->Value = oneDayLater;
		}
		String^ folder = "R:\\Archive\\";
		cli::array<String^>^ dir = System::IO::Directory::GetDirectories(folder);
		string datePickerFrom = msclr::interop::marshal_as<string>(dateTimePicker1->Text);//date from "from" box
		string datePickerTo = msclr::interop::marshal_as<string>(dateTimePicker2->Text);//date from "to" box
		progressBar1->Maximum = getDifference({ ((datePickerFrom[2] - 48) * 10 + (datePickerFrom[3] - 48)), ((datePickerFrom[0] - 48) * 10 + (datePickerFrom[1] - 48)),((datePickerFrom[4] - 48) * 1000 + (datePickerFrom[5] - 48) * 100 + (datePickerFrom[6] - 48) * 10 + (datePickerFrom[7] - 48)) }, { ((datePickerTo[2] - 48) * 10 + (datePickerTo[3] - 48)), ((datePickerTo[0] - 48) * 10 + (datePickerTo[1] - 48)),((datePickerTo[4] - 48) * 1000 + (datePickerTo[5] - 48) * 100 + (datePickerTo[6] - 48) * 10 + (datePickerTo[7] - 48)) })*300;
		for (int j = 0; j < dir->Length; ++j) {
			String^ cliString = dir[j];  //this and next line is for converting String^ to string
			string dirString = msclr::interop::marshal_as<string>(cliString);//see above
			//cout << dirString << endl;
			if ((dirDateYearToIntSearch(dirString) >= dateYearToIntSearch(datePickerFrom)) && (dirDateYearToIntSearch(dirString) <= dateYearToIntSearch(datePickerTo))) {
				cli::array<String^>^ dirTwo = System::IO::Directory::GetDirectories(dir[j]);
				for (int i = 0; i < dirTwo->Length; ++i) {
					String^ cliStringTwo = dirTwo[i];//this and next line is for converting String^ to string
					string dirStringTwo = msclr::interop::marshal_as<string>(cliStringTwo);//see above
					//cout << dirStringTwo << endl;
					//progressBar1->PerformStep();
					if (dirFullDateYearToIntSearch(dirStringTwo) >= dateFullDateYearToIntSearch(datePickerFrom) && dirFullDateYearToIntSearch(dirStringTwo) <= dateFullDateYearToIntSearch(datePickerTo)) {
						String^ fileSearch = textBox2->Text;  //this appends file name to HTMl
						cli::array<String^>^ fileList = fileSearch->Split(';');
						for (int k = 0; k < fileList->Length; ++k) {
							fileList[k] = fileList[k] + "*.html";
						}
						cli::array<String^>^ fileR = { "null" };
						int tempSize;
						int tempSize2;
						for (int k = 0; k < fileList->Length; ++k) {
							cli::array<String^>^ tempFileR = System::IO::Directory::GetFiles(dirTwo[i], fileList[k]);
							tempSize = fileR->Length;
							tempSize2 = tempFileR->Length;
							if (fileR[0] == "null") {
								tempSize = 0;
							}
							else {
								tempSize = fileR->Length;
							}
							Array::Resize(fileR, tempSize + tempSize2);
							tempFileR->CopyTo(fileR, (tempSize));
						}
						label5->Text = "Loading.... Searching " + cliStringTwo;
						label5->Refresh();
						//progressBar1->PerformStep();
						for (int k = 0; k < fileR->Length; ++k) {
							String^ fileINeed = fileR[k];
							string fileName = msclr::interop::marshal_as<string>(fileINeed); //converts to string
							//cout << fileName << endl;
							String^ dataSearch = textBox1->Text;
							string stringtoSearchFor = msclr::interop::marshal_as<string>(dataSearch);
							replace(fileName.begin(), fileName.end(), '\\', '/');
							LoadSearchResults(fileName, stringtoSearchFor);
							progressBar1->PerformStep();
						}
					}
					
				}

			}
		}
		for (int i = 0; i < dir->Length; ++i) {
			if (dir[i]->Length > 17) {
				String^ cliStringTwo = dir[i];//this and next line is for converting String^ to string
				string dirStringTwo = msclr::interop::marshal_as<string>(cliStringTwo);//see above
				//cout << dirFullDateYearToIntSearchTwo(dirStringTwo) << " vs " << dateYearToIntSearch(datePickerFrom) << endl;
				//progressBar1->PerformStep();
				label5->Text = "Loading.... Searching " + cliStringTwo;
				label5->Refresh();
				//progressBar1->PerformStep();
				if ((dirFullDateYearToIntSearchTwo(dirStringTwo) >= dateFullDateYearToIntSearch(datePickerFrom)) && (dirFullDateYearToIntSearchTwo(dirStringTwo) <= dateFullDateYearToIntSearch(datePickerTo))) {
					String^ fileSearch = textBox2->Text;  //this appends file name to HTMl
					cli::array<String^>^ fileList = fileSearch->Split(';');
					for (int k = 0; k < fileList->Length; ++k) {
						fileList[k] = fileList[k] + "*.html";
					}
					cli::array<String^>^ fileR = {"null"};
					int tempSize;
					int tempSize2;
					for (int k = 0; k < fileList->Length; ++k) {
						cli::array<String^>^ tempFileR = System::IO::Directory::GetFiles(dir[i], fileList[k]);
						tempSize = fileR->Length;
						tempSize2 = tempFileR->Length;
						if (fileR[0] == "null") {
							tempSize = 0;
						}
						else {
							tempSize = fileR->Length;
						}
						Array::Resize(fileR, tempSize + tempSize2);
						tempFileR->CopyTo(fileR, (tempSize));
					}
					//progressBar1->PerformStep();
					for (int k = 0; k < fileR->Length; ++k) {
						String^ fileINeed = fileR[k];
						string fileName = msclr::interop::marshal_as<string>(fileINeed); //converts to string
						String^ dataSearch = textBox1->Text;
						string stringtoSearchFor = msclr::interop::marshal_as<string>(dataSearch);
						//cout << fileName << endl;
						replace(fileName.begin(), fileName.end(), '\\', '/');
						LoadSearchResults(fileName, stringtoSearchFor);
						progressBar1->PerformStep();
					}
				}
			}

		}
		DateTime localDate = DateTime::Now;
		String^ locallyDate = localDate.ToString("MM" + "dd" + "yyyy", System::Globalization::DateTimeFormatInfo::InvariantInfo);
		string localDateFormat = msclr::interop::marshal_as<string>(locallyDate);
		if ((dateFullDateYearToIntSearch(localDateFormat) <= dateFullDateYearToIntSearch(datePickerTo))) {
			label5->Text = "Loading.... Searching R:/";
			label5->Refresh();
			String^ fileSearch = textBox2->Text;  //this appends file name to HTMl
			cli::array<String^>^ fileList = fileSearch->Split(';');
			for (int k = 0; k < fileList->Length; ++k) {
				fileList[k] = fileList[k] + "*.html";
			}
			cli::array<String^>^ fileR = {"null"};
			int tempSize;
			int tempSize2;
			for (int k = 0; k < fileList->Length; ++k) {
				cli::array<String^>^ tempFileR = System::IO::Directory::GetFiles("R://", fileList[k]);
				tempSize = fileR->Length;
				tempSize2 = tempFileR->Length;
				if (fileR[0] == "null") {
					tempSize = 0;
				}
				else {
					tempSize = fileR->Length;
				}
				Array::Resize(fileR, tempSize + tempSize2);
				tempFileR->CopyTo(fileR, (tempSize));
			}
			//progressBar1->PerformStep();
			for (int k = 0; k < fileR->Length; ++k) {
				String^ fileINeed = fileR[k];
				string fileName = msclr::interop::marshal_as<string>(fileINeed); //converts to string
				String^ dataSearch = textBox1->Text;
				string stringtoSearchFor = msclr::interop::marshal_as<string>(dataSearch);
				//cout << fileName << endl;
				replace(fileName.begin(), fileName.end(), '\\', '/');
				LoadSearchResults(fileName, stringtoSearchFor);
				progressBar1->PerformStep();
			}
		}

		//cout << getSomeSearchResults(1).size() << endl;
		listBox1->Items->Clear();
		for (int i = 0; i < getSomeSearchResults(1).size(); ++i) {
			//String^ resultOfSearch = "file://" + gcnew String(getSomeSearchResults(1).at(i).GetSearchLocation().c_str());
			String^ resultOfSearch = gcnew String(getSomeSearchResults(1).at(i).GetSearchLocation().c_str());
			listBox1->Items->Add(resultOfSearch);
		}
		if (getSomeSearchResults(1).size() > 0) {
			listBox1->SelectedIndex = 0;
		}
		progressBar1->Maximum = 100;
		progressBar1->Value = 100;
		if (getSomeSearchResults(1).size() == 1) {
			label5->Text = "Complete.  Found 1 File";
		}
		else {
			label5->Text = "Complete.  Found " + getSomeSearchResults(1).size() + " Files";
		}
	}
		   
private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ test = listBox1->GetItemText(listBox1->SelectedItem);
	Process::Start(test);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	string stringtoSearchFor = msclr::interop::marshal_as<string>(textBox1->Text);
	string fileSearch = msclr::interop::marshal_as<string>(textBox2->Text);
	string datePickerFrom = msclr::interop::marshal_as<string>(dateTimePicker1->Text);//date from "from" box
	string datePickerTo = msclr::interop::marshal_as<string>(dateTimePicker2->Text);//date from "to" box
	writeSpreadSheet(stringtoSearchFor, fileSearch, datePickerFrom, datePickerTo);
	//MessageBox::Show("Saved");
	listBox2->Items->Add(textBox1->Text + " in " + textBox2->Text + " from " + dateTimePicker1->Text + " to " + dateTimePicker2->Text);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ loadSelected = listBox2->GetItemText(listBox2->SelectedItem);
	string stringtoSearchFor = msclr::interop::marshal_as<string>(loadSelected);
	//cout << stringtoSearchFor << endl;
	//cout << split(stringtoSearchFor, ' ')[0] << endl;
	//cout << split(stringtoSearchFor, ' ')[2] << endl;
	//cout << split(stringtoSearchFor, ' ')[4] << endl;
	//cout << split(stringtoSearchFor, ' ')[6] << endl;
	String^ searchFor = gcnew String(split(stringtoSearchFor, ' ')[0].c_str());
	String^ InFile = gcnew String(split(stringtoSearchFor, ' ')[2].c_str());
	String^ fromDate = gcnew String(split(stringtoSearchFor, ' ')[4].c_str());
	String^ toDate = gcnew String(split(stringtoSearchFor, ' ')[6].c_str());
	loadDate(searchFor, InFile, fromDate, toDate);
	String^ fileINeed = "savedSearches\\" + searchFor + "_" + InFile + "_" + fromDate + "_" + toDate + ".csv";
	string getThatFile = msclr::interop::marshal_as<string>(fileINeed);
	read_record(getThatFile);
	listBox1->Items->Clear();
	for (int i = 0; i < getSomeSearchResults(1).size(); ++i) {
		//String^ resultOfSearch = "file://" + gcnew String(getSomeSearchResults(1).at(i).GetSearchLocation().c_str());
		String^ resultOfSearch = gcnew String(getSomeSearchResults(1).at(i).GetSearchLocation().c_str());
		listBox1->Items->Add(resultOfSearch);
	}
	if (getSomeSearchResults(1).size() > 0) {
		listBox1->SelectedIndex = 0;
	}
	if (getSomeSearchResults(1).size() == 1) {
		label5->Text = "Complete.  Found 1 File";
	}
	else {
		label5->Text = "Complete.  Found " + getSomeSearchResults(1).size() + " Files";
	}
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	cli::array<String^>^ fileR = System::IO::Directory::GetFiles("savedSearches");//loads the saved searches
	for (int i = 0; i < fileR->Length; ++i) {
		String^ filRee = fileR[i];
		string stringtoSearchFor = msclr::interop::marshal_as<string>(filRee);
		stringtoSearchFor = stringtoSearchFor.substr(14);//get from "savedSearches" to the end
		String^ searchFor = gcnew String(split(stringtoSearchFor, '_')[0].c_str());
		String^ InFile = gcnew String(split(stringtoSearchFor, '_')[1].c_str());
		String^ fromDate = gcnew String(split(stringtoSearchFor, '_')[2].c_str());
		String^ toDate = gcnew String(split(split(stringtoSearchFor, '_')[3], '.')[0].c_str());//this gets rid of the ".csv"
		listBox2->Items->Add(searchFor + " in " + InFile + " from " + fromDate + " to " + toDate);
	}
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ loadSelected = listBox2->GetItemText(listBox2->SelectedItem);
	string stringtoSearchFor = msclr::interop::marshal_as<string>(loadSelected);
	String^ searchFor = gcnew String(split(stringtoSearchFor, ' ')[0].c_str());
	String^ InFile = gcnew String(split(stringtoSearchFor, ' ')[2].c_str());
	String^ fromDate = gcnew String(split(stringtoSearchFor, ' ')[4].c_str());
	String^ toDate = gcnew String(split(stringtoSearchFor, ' ')[6].c_str());
	String^ fileINeed = "savedSearches\\" + searchFor + "_" + InFile + "_" + fromDate + "_" + toDate + ".csv";
	const char* deleteThatFile = msclr::interop::marshal_as<string>(fileINeed).c_str();
	deleteFile(deleteThatFile);
	listBox2->Items->Remove(searchFor + " in " + InFile + " from " + fromDate + " to " + toDate);
}
private: System::Void fromOneMonthAgoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	DateTime lastMonth = DateTime::Now.AddMonths(-1);
	dateTimePicker1->Value = lastMonth;
}
private: System::Void toOneWeekRangeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	DateTime fromDate = dateTimePicker1->Value;
	DateTime oneWeekLater = fromDate.AddDays(7);
	dateTimePicker2->Value = oneWeekLater;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	cli::array<String^>^ fileR;
	int aCount = (listBox1->Items->Count);
	fileR = gcnew cli::array <String^> (aCount);
	progressBar1->Value = 0;
	progressBar1->Step = 1;
	label5->Text = "Loading....";
	label5->Refresh();

	ClearSearchResults();
	progressBar1->Maximum = (aCount) * 2;
	for (int j = 0; j < aCount; ++j) {
		//fileR[j] = listBox1->Items[j]->ToString();
		fileR[j] = listBox1->GetItemText(listBox1->Items[j]);
		progressBar1->PerformStep();
	}
	listBox1->Items->Clear();
	for (int k = 0; k < fileR->Length; ++k) {
		label5->Text = "Loading.... Searching " + fileR[k];
		label5->Refresh();
		String^ fileINeed = fileR[k];
		string fileName = msclr::interop::marshal_as<string>(fileINeed); //converts to string
		String^ dataSearch = textBox3->Text;
		string stringtoSearchFor = msclr::interop::marshal_as<string>(dataSearch);
		//replace(fileName.begin(), fileName.end(), '\\', '/');
		LoadSearchResults(fileName, stringtoSearchFor);
		progressBar1->PerformStep();
	}

	//cout << getSomeSearchResults(1).size() << endl;
	for (int i = 0; i < getSomeSearchResults(1).size(); ++i) {
		//String^ resultOfSearch = "file://" + gcnew String(getSomeSearchResults(1).at(i).GetSearchLocation().c_str());
		String^ resultOfSearch = gcnew String(getSomeSearchResults(1).at(i).GetSearchLocation().c_str());
		listBox1->Items->Add(resultOfSearch);
	}
	if (getSomeSearchResults(1).size() > 0) {
		listBox1->SelectedIndex = 0;
	}
	//progressBar1->Maximum = 100;
	progressBar1->Value = progressBar1->Maximum;
	if (getSomeSearchResults(1).size() == 1) {
		label5->Text = "Complete.  Found 1 File";
	}
	else {
		label5->Text = "Complete.  Found " + getSomeSearchResults(1).size() + " Files";
	}
	textBox1->Text = textBox1->Text + ";" + textBox3->Text;
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = textBox1->Text + ";";
	textBox1->Select(textBox1->Text->Length, 0);
	textBox1->Focus();
	textBox1->ScrollToCaret();
	//textBox1->Select();
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox2->Text = textBox2->Text + ";";
	textBox2->Select(textBox2->Text->Length, 0);
	textBox2->Focus();
	textBox2->ScrollToCaret();
}
private: System::Void toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox2->Text = "3981";
}
private: System::Void m552ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox2->Text = "M552";
}
};
}
