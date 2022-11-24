#pragma once

class EnumerableUtils {
public:

	template <typename T>
	static T Random(TArray<T> Source);

	template <typename T>
	static TArray<T> GetShuffled(TArray<T> Source);
};

template <typename T>
T EnumerableUtils::Random(TArray<T> Source) {
	return Source[FMath::RandRange(0, Source.Num() - 1)];
}

template <typename T>
TArray<T> EnumerableUtils::GetShuffled(TArray<T> Source) {
	TArray<T> Result;
	TArray<T> Copy(Source);
	while (Copy.Num() > 0) {
		T Item = Random(Copy);
		Result.Add(Item);
		Copy.Remove(Item);
	}
	return Result;
}
