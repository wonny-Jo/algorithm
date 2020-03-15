<N; j++)
		{
		cin >> command;
		if (command == 1)
		{
			cin >> a;
			V += a;
			distSum += V;
		}
		else if (command == 2)
		{
			cin >> a;
			V = (V - a) > 0 ? V - a : 0;
			distSum += V;
		}
		else if (command == 0)
		{
			distSum += V;
		}
		}
cout << "#" << i + 1 << " " << distSum << endl;
	}

	return 0;
}