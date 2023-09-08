compile:
	 g++ App.cpp MainFrame/*.cpp `wx-config --cxxflags --libs` -o app.out
run:
	./app.out
clean:
	rm -rf *.out
clear:
	unset GTK_PATH
crun:
	make compile
	make run