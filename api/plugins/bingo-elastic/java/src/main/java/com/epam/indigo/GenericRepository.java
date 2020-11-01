package com.epam.indigo;

import com.epam.indigo.model.IndigoRecord;

import java.io.IOException;
import java.util.List;
import java.util.stream.Stream;

public interface GenericRepository<T extends IndigoRecord> {

    Stream<T> stream();

    boolean indexRecords(Iterable<T> records, T record) throws IOException;

    boolean indexRecords(List<T> records) throws IOException;

    boolean deleteAllRecords() throws IOException;

}
