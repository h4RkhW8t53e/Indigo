package com.epam.indigo.predicate;

import com.epam.indigo.model.IndigoRecord;
import com.epam.indigo.model.NamingConstants;
import org.elasticsearch.script.Script;

import java.util.HashMap;
import java.util.Map;

public class ExactMatch<T extends IndigoRecord> extends BaseMatch<T> {

    public ExactMatch(T target) {
        super(target);
    }

    @Override
    public Script generateScript() {
        Map<String, Object> map = new HashMap<>();
        map.put("source", "_score / doc['" + NamingConstants.SUB_FINGERPRINT_LEN + "'].value");
        return Script.parse(map);
    }

    @Override
    public String getMinimumShouldMatch(int length) {
        return "100%";
    }

    @Override
    public float getThreshold() {
        return 1.0f;
    }

    @Override
    public String getFingerprintName() {
        return NamingConstants.SUB_FINGERPRINT;
    }
}
